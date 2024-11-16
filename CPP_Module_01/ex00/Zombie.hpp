/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:03:15 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/16 12:57:37 by sylabbe          ###   ########.fr       */
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

    private:

        Zombie();
        std::string _name;
};

Zombie* newZombie( std::string name );
Zombie* newZombie( const char* name );
void randomChump( std::string name );
void randomChump( const char* name );

#endif