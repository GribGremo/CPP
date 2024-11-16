/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:35:32 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/16 14:37:41 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <sstream>

class Zombie
{
    public:

        Zombie(std::string name);
        ~Zombie(void);

        void announce( void );
        void set_name(std::string name);

    private:

        Zombie();
        std::string _name;
};

Zombie* zombieHorde( int N, std::string name );
Zombie* zombieHorde( int N, const char* name );

#endif