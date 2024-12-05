/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:07:20 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/05 17:12:16 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define RESET "\033[0m"
#define RED "\033[31m"

Bureaucrat* createBureaucrat(int grade, std::string name);
void printBureaucrat(Bureaucrat* br, std::string name);
void incrGrade(Bureaucrat* br, std::string name);


int main()
{
    Bureaucrat* Bob = createBureaucrat(1, "Bob");
    Bureaucrat* Steve = createBureaucrat(150, "Steve");
    Bureaucrat* Bernard = createBureaucrat(0, "Bernard");
    Bureaucrat* Andre = createBureaucrat(151, "Andre");

    printBureaucrat(Bob, "Bob");
    printBureaucrat(Steve, "Steve");
    printBureaucrat(Bernard, "Bernard");
    printBureaucrat(Andre, "Andre");

    // incrGrade(Bob, Bob->getName());
    // incrGrade(Steve, Steve->getName());
    // incrGrade(Bernard, "Bernard");
    // incrGrade(Andre, "Andre");
    try
    {
        Bob->incGrade();
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << RED << "Cannot increment " << e.what() << RESET << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << RED << "Cannot increment " <<  e.what() << RESET << std::endl;
    }
    printBureaucrat(Bob, "Bob");


    delete Bob;
    delete Steve;
    delete Bernard;
    delete Andre;
}

Bureaucrat* createBureaucrat(int grade, std::string name)
{
    Bureaucrat* br = NULL;
    try
    {
        br = new Bureaucrat(grade, name);
        return br;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << RED << "Cannot build " << name << e.what() << RESET << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << RED << "Cannot build " << name << e.what() << RESET << std::endl;
    }
    // Here we can see that br doesn't exists if an exception has been thrown, the object has not been finished 
    // std::cout << br << std::endl;
    return br;
}

void printBureaucrat(Bureaucrat* br, std::string name)
{
    if(br != NULL)
        std::cout << *br << std::endl;
    else
        std::cout << RED << name << " is not instantiated" << RESET << std::endl;
}

void incrGrade(Bureaucrat* br, std::string name)
{
    if (br == NULL)
        return ;
    try
    {
        br->incGrade();
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << RED << "Cannot increment " << name << e.what() << RESET << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << RED << "Cannot increment " << name << e.what() << RESET << std::endl;
    }
    return ;
    
}