/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:32 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/04 12:56:54 by sylabbe          ###   ########.fr       */
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

    virtual Animal& operator=(const Animal& src);

    virtual void makeSound() const;

    std::string getType() const;

    virtual void setIdea(const std::string& idea, const int it_idea);
    virtual const std::string getIdea(const int it_idea);

    protected:

    std::string type;
    
};

#endif