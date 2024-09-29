/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:28:44 by sylabbe           #+#    #+#             */
/*   Updated: 2024/09/28 15:53:18 by sylabbe          ###   ########.fr       */
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

        HumanA(Weapon &weapon_type, std::string name);//?ref
        ~HumanA(void);
        void attack(void)const;
    private:

        Weapon &_weapon;
        std::string _name;
};


#endif