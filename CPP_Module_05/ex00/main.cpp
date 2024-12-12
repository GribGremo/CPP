/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:07:20 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/12 10:25:10 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define RESET "\033[0m"
#define RED "\033[31m"

Bureaucrat* createBureaucrat(int grade, std::string& name);
void printBureaucrat(Bureaucrat* br, const std::string& name);
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

    std::cout << "~~~~~~~~~~~BUREAUCRAT COPY TEST~~~~~~~~~~~" << std::endl;

    *Bob=*Steve;
    printBureaucrat(Bob, name1);
    Bureaucrat test(*Bob);
    printBureaucrat(&test, "test");
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

void printBureaucrat(Bureaucrat* br,const std::string& name)
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
