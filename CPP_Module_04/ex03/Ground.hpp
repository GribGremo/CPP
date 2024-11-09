/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ground.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:19:43 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/09 10:30:43 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GROUND_LIST_HPP
# define GROUND_LIST_HPP
#include "AMateria.hpp"

class Ground_List
{
    public:
    AMateria* head;

    Ground_List();
    Ground_List(const Ground_List& src);
    ~Ground_List();

    Ground_List& operator=(const Ground_List& src);

    void push(const AMateria* m);

    void printList();
};

#endif