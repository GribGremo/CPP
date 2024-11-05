/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:22:28 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/02 11:47:06 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP
# include <iostream>
class WrongAnimal {
    public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& src);
    virtual ~WrongAnimal();

    WrongAnimal& operator=(const WrongAnimal& src);

    void makeSound() const;

    std::string getType() const;

    protected:
    std::string type;
};

#endif