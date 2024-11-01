/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:32 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/01 17:37:41 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal{
    public:

    Animal();
    Animal(const Animal& src);
    ~Animal();

    Animal& operator=(const Animal& src);

    virtual void makeSound() const;

    virtual std::string getType() const;

    protected:

    std::string type;
    
};

#endif