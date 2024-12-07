/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:07:20 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/07 16:23:18 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
// #include "Form.hpp"

#define RESET "\033[0m"
#define RED "\033[31m"

Bureaucrat* createBureaucrat(int grade, std::string& name);
void printBureaucrat(Bureaucrat* br, std::string& name);
void changeGrade(Bureaucrat* br, std::string& name, void (Bureaucrat::*change)());

Form* createForm(int grade_to_sign, int grade_to_execute, std::string& name);
void printForm(Form* br, std::string& name);

int main()
{
    std::string name1 = "Bob";
    std::string name2 = "Steve";

    std::string name3 = "A-75";
    std::string name4 = "B-34";
    std::string name5 = "C-22";
    std::string name6 = "D-26";
    std::string name7 = "E-89";
    std::string name8 = "F-47";


    std::cout << "~~~~~~~~~~~BUREAUCRAT CREATION~~~~~~~~~~~" << std::endl;

    Bureaucrat* Bob = createBureaucrat(1, name1);
    Bureaucrat* Steve = createBureaucrat(150, name2);
    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~FORM CREATION~~~~~~~~~~~" << std::endl;

    Form* a75 = createForm(1, 1, name3);
    Form* b34 = createForm(150, 150, name4);
    Form* c22 = createForm(0, 1, name5);
    Form* d26 = createForm(1, 0, name6);
    Form* e89 = createForm(150, 151, name7);
    Form* f47 = createForm(151, 150, name8);
    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~FORM PRINT~~~~~~~~~~~" << std::endl;

    printForm(a75, name3);
    printForm(b34, name4);
    printForm(c22, name5);
    printForm(d26, name6);
    printForm(e89, name7);
    printForm(f47, name8);

    std::cout << "~~~~~~~~~~~SIGN FORM~~~~~~~~~~~" << std::endl;

    Bob->signForm(*a75);
    Bob->signForm(*b34);

    Steve->signForm(*a75);
    Steve->signForm(*b34);

    std::cout << "~~~~~~~~~~~BUREAUCRAT DESTRUCTION~~~~~~~~~~~" << std::endl;

    delete Bob;
    delete Steve;
}

Bureaucrat* createBureaucrat(int grade, std::string& name)
{
    Bureaucrat* br = NULL;
    try
    {
        br = new Bureaucrat(grade, name);
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

Form* createForm(int grade_to_sign, int grade_to_execute, std::string& name)
{
    Form* fm = NULL;
    try
    {
        fm = new Form(name, grade_to_sign, grade_to_execute);
        return fm;
    }
    catch (Form::GradeTooLowException& e)
    {
        std::cerr << RED << "Cannot build form \"" << name << "\": " << e.what() << RESET << std::endl;
    }
    catch (Form::GradeTooHighException& e)
    {
        std::cerr << RED << "Cannot build form \"" << name << "\": " << e.what() << RESET << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << RED << "Cannot build form \"" << name << "\": " << e.what() << RESET << std::endl;
    }
    return fm;
}

void printForm(Form* br, std::string& name)
{
    if(br != NULL)
        std::cout << *br << std::endl;
    else
        std::cout << RED << name << " is not instantiated" << RESET << std::endl;
}