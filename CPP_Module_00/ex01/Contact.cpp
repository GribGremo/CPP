/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:01:11 by sylabbe           #+#    #+#             */
/*   Updated: 2024/09/15 14:31:29 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() : _first_name(""), _last_name(""), _nickname(""), _phone_number(""), _darkest_secret(""){
	return;
}

Contact::Contact(std::string f_name, std::string l_name, std::string nname,std::string p_number,std::string d_secret) {
	this->_first_name = f_name;
	this->_last_name = l_name;
	this->_nickname = nname;
	this->_phone_number = p_number;
	this->_darkest_secret = d_secret;
	return;
}

Contact::~Contact(void) {
	return;
}

std::string Contact::get_first_name() const{
	return(this->_first_name);
}

std::string	Contact::get_last_name() const{
	return(this->_last_name);
}

std::string	Contact::get_nickname() const{
	return(this->_nickname);
}

std::string	Contact::get_phone_number() const{
	return(this->_phone_number);
}

std::string	Contact::get_darkest_secret() const{
	return(this->_darkest_secret);
}