/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:07:20 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/09 17:59:04 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

#define RESET "\033[0m"
#define RED "\033[31m"

Bureaucrat* createBureaucrat(int grade, std::string& name);
void printBureaucrat(Bureaucrat* br, std::string& name);
void changeGrade(Bureaucrat* br, std::string& name, void (Bureaucrat::*change)());

AForm* createForm(const std::string& target, const std::string& formType);
void printForm(AForm* br, std::string& name);

int main()
{
    std::string name1 = "Bob";
    std::string name2 = "Steve";

    std::cout << "~~~~~~~~~~~BUREAUCRAT CREATION~~~~~~~~~~~" << std::endl;

    Bureaucrat* Bob = createBureaucrat(1, name1);
    Bureaucrat* Steve = createBureaucrat(150, name2);
    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~FORM CREATION~~~~~~~~~~~" << std::endl;

    AForm* shruberry = createForm(".", "Shrubbery");
    AForm* presidentialpardon = createForm("","PresidentialPardon");
    AForm* robotomy = createForm("", "Robotomy");

    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~FORM PRINT~~~~~~~~~~~" << std::endl;

    // printForm(shruberry);
    // printForm(presidentialpardon);
    // printForm(robotomy);

    std::cout << std::endl;


    std::cout << "~~~~~~~~~~~SIGN FORM~~~~~~~~~~~" << std::endl;

    Steve->signForm(*shruberry);
    Steve->signForm(*presidentialpardon);
    Steve->signForm(*presidentialpardon);




    // printForm(a75, name3);
    // printForm(b34, name4);

    Bob->signForm(*shruberry);
    Bob->signForm(*presidentialpardon);
    Bob->signForm(*presidentialpardon);

    printForm(a75, name3);
    printForm(b34, name4);
    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~BUREAUCRAT DESTRUCTION~~~~~~~~~~~" << std::endl;

    delete Bob;
    delete Steve;
    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~FORM DESTRUCTION~~~~~~~~~~~" << std::endl;

    delete shruberry;
    delete presidentialpardon;
    delete robotomy;

    std::cout << std::endl;

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

AForm* createForm(const std::string& target, const std::string& formType)
{
    AForm* fm = NULL;
    if (formType != "Shrubbery" && formType != "Robotomy" && formType != "PresidentialPardon")
    {
        std::cout << "Invalid form type, none created" << std::endl;
    }
    try
    {
        if (formType == "Shrubbery")
            fm = new ShrubberyCreationForm(target);
        else if (formType == "Robotomy")
            fm = new RobotomyRequestForm(target);
        else if (formType == "PresidentialPardon")
            fm = new PresidentialPardonForm(target);
        return fm;
    }
    catch (AForm::GradeTooLowException& e)
    {
        std::cerr << RED << "Cannot build form \"" << formType << "\": " << e.what() << RESET << std::endl;
    }
    catch (AForm::GradeTooHighException& e)
    {
        std::cerr << RED << "Cannot build form \"" << formType << "\": " << e.what() << RESET << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << RED << "Cannot build form \"" << formType << "\": " << e.what() << RESET << std::endl;
    }
    return fm;
}

// void printForm(AForm* br, std::string& name)
// {
//     if(br != NULL)
//         std::cout << *br << std::endl;
//     else
//         std::cout << RED << name << " is not instantiated" << RESET << std::endl;
// }