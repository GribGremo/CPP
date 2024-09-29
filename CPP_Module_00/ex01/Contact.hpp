/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:01:14 by sylabbe           #+#    #+#             */
/*   Updated: 2024/09/15 15:32:19 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

class	Contact { 
public:

    Contact();
	Contact(std::string _first_name, std::string _last_name, std::string _nickname,std::string _phone_number,std::string _darkest_secret);
	~Contact(void);

    std::string    get_first_name(void) const;
    std::string    get_last_name(void) const;
    std::string    get_nickname(void) const;
    std::string    get_phone_number(void) const;
    std::string    get_darkest_secret(void) const;

private:

    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone_number;
    std::string _darkest_secret;
};

#endif