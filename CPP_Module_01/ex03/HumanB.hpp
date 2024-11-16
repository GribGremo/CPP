/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:29:03 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/16 15:11:35 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <iostream>
# include <sstream>
#include "Weapon.hpp"


class HumanB
{
    public:

        HumanB(void);
        HumanB(const std::string& name);
        ~HumanB(void);
        void attack(void)const;
        void setWeapon(Weapon *weapon);

    private:

        Weapon *_weapon;
        std::string _name;
};

#endif