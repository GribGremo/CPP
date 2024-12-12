/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:07:20 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/12 17:08:34 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

#define RESET "\033[0m"
#define RED "\033[31m"

Bureaucrat* createBureaucrat(int grade, const std::string& name);
void printBureaucrat(Bureaucrat* br, std::string& name);
void changeGrade(Bureaucrat* br, std::string& name, void (Bureaucrat::*change)());

AForm* createForm(const std::string& target, const std::string& formType);
void printForm(AForm* br, std::string& name);

int main()
{
    std::cout << "~~~~~~~~~~~BUREAUCRAT CREATION~~~~~~~~~~~" << std::endl;

    // Bureaucrat* boss = createBureaucrat(1, "Gaetan");
    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~INTERN CREATION~~~~~~~~~~~" << std::endl;
    Intern drunge;
    std::cout << std::endl;


    AForm* test = drunge.makeForm("robotomy   request", "osef");
    test->pform();
    // std::cout << "~~~~~~~~~~~FORM CREATION~~~~~~~~~~~" << std::endl;

    // AForm* shruberry = drunge.makeForm("ShrubberyCreationForm", "forest");
    // AForm* robotomy = drunge.makeForm("robotomy   request", "Corrector");
    // AForm* presidentialpardon = drunge.makeForm("PresidentialPardonForm", "forest");
    // std::cout << std::endl;

    // std::cout << "~~~~~~~~~~~FORM PRINT~~~~~~~~~~~" << std::endl;

    // shruberry->pform();
    // robotomy->pform();
    // presidentialpardon->pform();
    // std::cout << std::endl;

    // std::cout << "~~~~~~~~~~~EXECUTE FORM~~~~~~~~~~~" << std::endl;

    // std::cout << "Grade 1: Unsigned form:" << std::endl;
    // boss->executeForm(*shruberry);
    // boss->executeForm(*robotomy);
    // boss->executeForm(*presidentialpardon);
    // std::cout << std::endl;

    // std::cout << "~~~~~~~~~~~SIGN FORM~~~~~~~~~~~" << std::endl;

    // std::cout << "Grade 1:" << std::endl;
    // boss->signForm(*shruberry);
    // boss->signForm(*robotomy);
    // boss->signForm(*presidentialpardon);
    // std::cout << std::endl;

    // std::cout << "~~~~~~~~~~~FORM PRINT~~~~~~~~~~~" << std::endl;

    // shruberry->pform();
    // presidentialpardon->pform();
    // robotomy->pform();
    // std::cout << std::endl;

    // std::cout << "~~~~~~~~~~~EXECUTE FORM~~~~~~~~~~~" << std::endl;

    // std::cout << "Grade 1:" << std::endl;
    // boss->executeForm(*shruberry);
    // boss->executeForm(*presidentialpardon);
    // for (int i = 0; i < 10; i++)
    //     boss->executeForm(*robotomy);
    // std::cout << std::endl;

    // std::cout << "~~~~~~~~~~~BUREAUCRAT DESTRUCTION~~~~~~~~~~~" << std::endl;

    // delete boss;

    // std::cout << std::endl;

    // std::cout << "~~~~~~~~~~~FORM DESTRUCTION~~~~~~~~~~~" << std::endl;

    // delete shruberry;
    // delete presidentialpardon;
    // delete robotomy;

    // std::cout << std::endl;

}

Bureaucrat* createBureaucrat(int grade, const std::string& name)
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

