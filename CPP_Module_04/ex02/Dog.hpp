/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:37 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/05 11:14:44 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
#include "A_Animal.hpp"
#include "Brain.hpp"
class Dog : public A_Animal{
    public:

    Dog();
    Dog(const Dog& src);
    ~Dog();

    Dog& operator=(const Dog& src);

    void makeSound() const;
    
    void setIdea(const std::string& idea, const int it_idea);
    const std::string getIdea(const int it_idea);

    private:
    Brain* _b;
};

#endif