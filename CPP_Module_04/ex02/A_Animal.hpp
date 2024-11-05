/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_A_Animal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:32 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/04 21:37:21 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_ANIMAL_HPP
# define A_ANIMAL_HPP
# include <iostream>

class A_Animal{
    public:

    A_Animal();
    A_Animal(const A_Animal& src);
    virtual ~A_Animal();

    virtual A_Animal& operator=(const A_Animal& src);

    virtual void makeSound() const = 0;

    std::string getType() const;

    virtual void setIdea(const std::string& idea, const int it_idea) = 0;
    virtual const std::string getIdea(const int it_idea) = 0;

    protected:

    std::string type;
    
};

#endif