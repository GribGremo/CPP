/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:37 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/02 13:56:53 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"
class Dog : public Animal{
    public:

    Dog();
    Dog(const Dog& src);
    ~Dog();

    Dog& operator=(const Dog& src);

    void makeSound() const;

    private:
    Brain* b;

};

#endif