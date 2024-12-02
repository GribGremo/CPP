/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:37:20 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/30 12:08:17 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include "Ground_List.hpp" // TEST

class Character : public ICharacter
{
    public:
    static Ground_List* ground; // Static pointer to an instance of Ground share between all characters
    static int countCharacter; // Static integer (number of characters active) share between all characters
    
    Character();
    Character(const std::string& name);
    Character(const Character& src);
    ~Character();

    Character& operator=(const Character& src);

    std::string const & getName() const;

    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
    void print_inventory();


    private:
    AMateria *inventory[4];
    std::string name;
};

#endif