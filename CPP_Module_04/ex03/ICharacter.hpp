/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:19:34 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/06 12:57:54 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP
# include <iostream>//
# include "AMateria.hpp"

class ICharacter
{
    public:
    ICharacter();
    ICharacter(const ICharacter& src);
    virtual ~ICharacter();

    ICharacter& operator=(const ICharacter& src);

    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;

    protected:
    AMateria *inventory[4];
    std::string name;//A voir si il faut le creer ici ou dans la derivee Character
};
#endif