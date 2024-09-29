/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:35:32 by sylabbe           #+#    #+#             */
/*   Updated: 2024/09/19 15:20:15 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <sstream>

class Zombie
{
    public:

        Zombie();
        Zombie(std::string name);
        ~Zombie(void);

        void announce( void );
        void set_name(std::string name);

    private:

        std::string _name;
};

Zombie* zombieHorde( int N, std::string name );


#endif