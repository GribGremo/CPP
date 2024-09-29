/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:01:23 by sylabbe           #+#    #+#             */
/*   Updated: 2024/09/18 08:35:52 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <iomanip>
# include <sstream>
# include "Contact.hpp"

class PhoneBook
{
  public:
	PhoneBook();
	~PhoneBook(void);

	int     add_contact();
	int     search_contact();
	void    display_lst_contact(Contact *array_ctc);
	void    display_single_contact(const Contact &ctc);

	Contact *get_ctc_array();
	int     get_array_index();

  private:
	int		_saved_contacts;
	int     _array_index;
	Contact _ctc_array[8];
};

#endif