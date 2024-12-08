/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:07:20 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/07 12:36:09 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define RESET "\033[0m"
#define RED "\033[31m"

Bureaucrat* createBureaucrat(int grade, std::string& name);
void printBureaucrat(Bureaucrat* br, std::string& name);
void changeGrade(Bureaucrat* br, std::string& name, void (Bureaucrat::*change)());


int main()
{
    std::string name1 = "Bob";
    std::string name2 = "Steve";
    std::string name3 = "Bernard";
    std::string name4 = "Andre";


    std::cout << "~~~~~~~~~~~BUREAUCRAT CREATION~~~~~~~~~~~" << std::endl;
    Bureaucrat* Bob = createBureaucrat(1, name1);
    Bureaucrat* Steve = createBureaucrat(150, name2);
    Bureaucrat* Bernard = createBureaucrat(0, name3);
    Bureaucrat* Andre = createBureaucrat(151, name4);
    std::cout << std::endl;


    std::cout << "~~~~~~~~~~~BUREAUCRAT PRINT~~~~~~~~~~~" << std::endl;

    printBureaucrat(Bob, name1);
    printBureaucrat(Steve, name2);
    printBureaucrat(Bernard, name3);
    printBureaucrat(Andre, name4);
    std::cout << std::endl;


    std::cout << "~~~~~~~~~~~BOB CHANGE GRADE~~~~~~~~~~~" << std::endl;

    changeGrade(Bob, name1, &Bureaucrat::decGrade);
    printBureaucrat(Bob, name1);

    changeGrade(Bob, name1, &Bureaucrat::incGrade);
    printBureaucrat(Bob, name1);
    
    changeGrade(Bob, name1, &Bureaucrat::incGrade);
    printBureaucrat(Bob, name1);
    std::cout << std::endl;


    std::cout << "~~~~~~~~~~~STEVE CHANGE GRADE~~~~~~~~~~~" << std::endl;


    changeGrade(Steve, name2, &Bureaucrat::incGrade);
    printBureaucrat(Steve, name2);

    changeGrade(Steve, name2, &Bureaucrat::decGrade);
    printBureaucrat(Steve, name2);

    changeGrade(Steve, name2, &Bureaucrat::decGrade);
    printBureaucrat(Steve, name2);
    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~BUREAUCRAT DESTRUCTION~~~~~~~~~~~" << std::endl;

    delete Bob;
    delete Steve;
    delete Bernard;//Those two have not been allocated, the try of constructor fail
    delete Andre;//
}

Bureaucrat* createBureaucrat(int grade, std::string& name)
{
    Bureaucrat* br = NULL;
    try
    {
        br = new Bureaucrat(grade, name);
        //Here if an exception occured during the constructor, RAII (Resource Acquisition Is Initialization) handle everything (allocation, fd, mutex), meaning nothing is allocated anymore 
        return br;
    }
    catch (Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << RED << "Cannot build \"" << name << "\": " << e.what() << RESET << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << RED << "Cannot build \"" << name << "\": " << e.what() << RESET << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << RED << "Cannot build \"" << name << "\": " << e.what() << RESET << std::endl;
    }
    // Here we can see that br doesn't exists if an exception has been thrown, the object has not been finished 
    // std::cout << br << std::endl;
    return br;
}

void printBureaucrat(Bureaucrat* br, std::string& name)
{
    if(br != NULL)
        std::cout << *br << std::endl;
    else
        std::cout << RED << name << " is not instantiated" << RESET << std::endl;
}

void changeGrade(Bureaucrat* br, std::string& name, void (Bureaucrat::*change)())
{
    if (br == NULL)
    {
        std::cout << RED << name << " is not instantiated" << RESET << std::endl;
        return ;
    }
    else if (change == NULL)
    {
        std::cout << RED << "Function pointer is NULL" << RESET << std::endl;
        return ;
    }

    try
    {
        (br->*change)();
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << RED << "Cannot decrement \"" << name << "\": " << e.what() << RESET << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << RED << "Cannot increment \"" << name << "\": " << e.what() << RESET << std::endl;
    }
    return ;
}

/*
C++17

Ce qu'il faut savoir
std::get :

L'appel à std::get<Type>(variant) lève une exception de type std::bad_variant_access si le type demandé n'est pas celui actuellement contenu dans le std::variant.
std::holds_alternative<Type> (préférable !) :

Une méthode plus propre pour tester le type avant d'utiliser std::get est d'utiliser std::holds_alternative<Type>(variant).
Cela retourne un booléen, évitant les exceptions.

 if (std::holds_alternative<std::string>(myVariant)) {
        std::cout << "It's a std::string: " << std::get<std::string>(myVariant) << std::endl;
    } else if (std::holds_alternative<int>(myVariant)) {
        std::cout << "It's an int: " << std::get<int>(myVariant) << std::endl;
    } else if (std::holds_alternative<char*>(myVariant)) {
        std::cout << "It's a char*: " << std::get<char*>(myVariant) << std::endl;
    } else {
        std::cout << "Unknown type!" << std::endl;
*/