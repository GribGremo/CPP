/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:58:23 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/30 14:22:54 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
    
    public:
    FragTrap();
    FragTrap(const std::string name);
    FragTrap(const FragTrap& src);
    ~FragTrap();

    FragTrap& operator=(const FragTrap& src);
    
    void highFivesGuys(void);
};

#endif