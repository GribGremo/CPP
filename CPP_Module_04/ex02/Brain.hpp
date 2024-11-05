/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:46:52 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/02 14:20:29 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
#include <iostream>
class Brain {
    public:
    Brain();
    Brain(const Brain& src);
    ~Brain();

    Brain& operator=(const Brain& src);

    std::string _ideas[100];

};

#endif