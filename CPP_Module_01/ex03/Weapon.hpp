/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:28:37 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/16 14:48:07 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# include <sstream>

class Weapon
{
    public:

        Weapon();
        Weapon(const std::string& type);
        ~Weapon(void);
        const std::string& getType(void);
        void setType(const std::string& type);

    private:

        std::string _type;
};


#endif