/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:18:52 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/06 12:33:08 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include <iostream>//
# include "ICharacter.hpp"

class Cure : public AMateria
{
    public:
    Cure();
    Cure(const Cure& src);
    ~Cure();
    
    Cure& operator=(const Cure& src);

    AMateria* clone() const;
    void use(ICharacter& target);

};

#endif