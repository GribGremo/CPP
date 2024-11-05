/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:22:23 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/02 11:34:58 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
    public:
    WrongCat();
    WrongCat(const WrongCat& src);
    virtual ~WrongCat();

    WrongCat& operator=(const WrongCat& src);

    void makeSound() const;

};

#endif