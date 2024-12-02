/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ground_List.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:19:43 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/02 16:38:30 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GROUND_LIST_HPP
# define GROUND_LIST_HPP
#include "AMateria.hpp"

class Ground_List
{
    public:

    Ground_List();
    Ground_List(const Ground_List& src);
    ~Ground_List();

    Ground_List& operator=(const Ground_List& src);

    void push(AMateria* m);

    void printList();

    private:

    AMateria* head;
};

#endif