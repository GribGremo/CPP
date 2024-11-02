/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:32 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/02 10:09:43 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal{
    public:

    Animal();
    Animal(const Animal& src);
    virtual ~Animal();

    Animal& operator=(const Animal& src);

    virtual void makeSound() const;

    std::string getType() const;

    protected:

    std::string type;
    
};

#endif