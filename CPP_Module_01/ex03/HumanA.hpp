/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:28:44 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/16 15:09:45 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include <sstream>
#include "Weapon.hpp"

class HumanA
{
    public:

        HumanA(Weapon &weapon_type, const std::string& name);
        ~HumanA(void);
        void attack(void)const;
    private:

        Weapon &_weapon;
        std::string _name;
};


#endif