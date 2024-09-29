/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:01:20 by sylabbe           #+#    #+#             */
/*   Updated: 2024/09/18 11:12:05 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	_array_index = 0;
	_saved_contacts = 0;
	return;
}

PhoneBook::~PhoneBook(void) {
	return;
}

Contact	*PhoneBook::get_ctc_array(){
	return (this->_ctc_array);
}

int	PhoneBook::get_array_index(){
	return(this->_array_index);
}

int str_is_alpha(std::string str)
{
    std::string::const_iterator it = str.begin();

    while(it != str.end())
    {
        if (!std::isalpha(*it))
            return (1);
        it++;
    }
    return (0);
}

int str_is_alnum(std::string str)
{
    std::string::const_iterator it = str.begin();

    while(it != str.end())
    {
        if (!std::isalnum(*it))
            return (1);
        it++;
    }
    return (0);
}

int str_is_digit(std::string str)
{
    std::string::const_iterator it = str.begin();

    while(it != str.end())
    {
        if (!std::isdigit(*it))
            return (1);
        it++;
    }
    return (0);
}

void print_value(std::string str)
{
	if (str.length() > 10)
	{
		str.resize(9);
		str.push_back('.');
		std::cout << str;
	}
	else
		std::cout << std::setw(10) << str;
	std::cout << "|";
}

int	PhoneBook::add_contact() {

	Contact& ctc = this->_ctc_array[this->_array_index];//
	std::string f_name;
    std::string l_name;
    std::string nname;
    std::string p_number;
    std::string d_secret;

    std::cout << "Enter first name:";
	std::getline(std::cin, f_name);
	if (std::cin.eof())
		return (1);
    if (str_is_alpha(f_name) || f_name.empty())
    {
        std::cout << "Invalid first name" << std::endl;
        return (0);
    }

    std::cout << "Enter last name:";
	std::getline(std::cin, l_name);
	if (std::cin.eof())
		return (1);
    if (str_is_alpha(l_name) || l_name.empty())
    {
        std::cout << "Invalid last name" << std::endl;
        return (0);
    }

    std::cout << "Enter nickname:";
	std::getline(std::cin, nname);
	if (std::cin.eof())
		return (1);
    if (str_is_alnum(nname) || nname.empty())
    {
        std::cout << "Invalid nickname" << std::endl;
        return (0);
    }

    std::cout << "Enter phone number:";
	std::getline(std::cin, p_number);
	if (std::cin.eof())
		return (1);
    if (str_is_digit(p_number) || p_number.empty())
    {
        std::cout << "Invalid phone number" << std::endl;
        return (0);
    }

    std::cout << "Enter darkest secret:";
	std::getline(std::cin, d_secret);
	if (std::cin.eof())
		return (1);
	// espace pas pris en compte : ERROR
    if (str_is_alnum(d_secret) || d_secret.empty())
    {
        std::cout << "Invalid darkest secret" << std::endl;
        return (0);
    }

    ctc = Contact(f_name,l_name,nname,p_number,d_secret);
	if (this->_saved_contacts < 8)
		this->_saved_contacts++;
	this->_array_index++;
	if (this->_array_index > 7)
		this->_array_index = 0;
	return (0);
}

int	PhoneBook::search_contact()
{
	std::string buffer;
	int nbr = -1;

	if (this->_saved_contacts == 0)
	{
		std::cout << "No contact in phonebook" << std::endl;
		return (0);
	}
	this->display_lst_contact(this->get_ctc_array());
	std::cout << "Enter contact index" << std::endl;
	std::getline(std::cin, buffer);
	if(std::cin.eof())
		return (1);
	std::stringstream ss(buffer);
	while(!(ss >> nbr) || !ss.eof() || (nbr < 0 || nbr >= _saved_contacts))
	{
		std::cout << "Invalid contact index, please try again" << std::endl;
		std::getline(std::cin, buffer);
		if(std::cin.eof())
			return (1);
		nbr = - 1;
		ss.str("");
        ss.clear();
		ss.str(buffer);
	}
	this->display_single_contact(this->get_ctc_array()[nbr]);
	return (0);
}

void	PhoneBook::display_lst_contact(Contact *array_ctc)
{
	int i = 0;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	while(i < (int)sizeof(array_ctc) && array_ctc[i].get_first_name() != "")//CAST EN INT
	{
		std::cout << "|";
		std::cout << std::setw(10) << i << "|";
		print_value(array_ctc[i].get_first_name());
		print_value(array_ctc[i].get_last_name());
		print_value(array_ctc[i].get_nickname());
		std::cout << std::endl;
		i++;
	}
	std::cout << std::endl;
}

void	PhoneBook::display_single_contact(const Contact& ctc)
{
	std::cout << "FIRST NAME     : " << ctc.get_first_name() << std::endl;
	std::cout << "LAST NAME      : " << ctc.get_last_name() << std::endl;
	std::cout << "NICKNAME       : " << ctc.get_nickname() << std::endl;
	std::cout << "PHONE NBR      : " << ctc.get_phone_number() << std::endl;
	std::cout << "DARKEST SECRET : " << ctc.get_darkest_secret() << std::endl;
}

