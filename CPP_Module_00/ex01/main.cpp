/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:01:17 by sylabbe           #+#    #+#             */
/*   Updated: 2024/09/15 16:03:38 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
// #include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int setup_contact(Contact& ctc);
int str_is_digit(std::string str);
int str_is_alnum(std::string str);
int str_is_alpha(std::string str);

int main(void)
{
    PhoneBook phobo;
    std::string buffer;
    
    std::cout << "********************************************" << std::endl;
    std::cout << "*                                          *" << std::endl;
    std::cout << "*                PHONEBOOK                 *" << std::endl;
    std::cout << "*                                          *" << std::endl;
    std::cout << "********************************************" << std::endl;
    
    while(buffer != "EXIT")
    {
        std::cout << std::endl << "=>Enter 'ADD' to add new contact" << std::endl << "=>Enter 'SEARCH' to search a contact" << std::endl << "=>Enter 'EXIT' to exit phonebook" << std::endl;
        std::getline(std::cin, buffer);
        if (std::cin.eof())
            return (1);
        else if (buffer == "ADD")
        {
            if(phobo.add_contact())
                return (1);
        }
        else if (buffer == "SEARCH")
        {
            if(phobo.search_contact())
                return (1);
        }
        else if (buffer == "EXIT")
            return (0);
        else
            std::cout << "Invalid command, please retry." << std::endl;
    }
}

