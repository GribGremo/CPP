/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:43 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/02 13:58:28 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"
class Cat : public Animal{
    public:

    Cat();
    Cat(const Cat& src);
    ~Cat();

    Cat& operator=(const Cat& src);

    void makeSound() const;

    private:
    Brain* b;
};

#endif