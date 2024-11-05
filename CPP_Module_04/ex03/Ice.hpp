/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:06:46 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/05 16:40:50 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include <iostream>//
# include "ICharacter.hpp"

class Ice
{
    public:
    Ice();
    Ice(const Ice& src);
    ~Ice();
    
    Ice& operator=(const Ice& src);

    AMateria* clone() const;
    void use(ICharacter& target);

};

#endif