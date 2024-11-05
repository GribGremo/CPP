/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:43 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/04 22:32:17 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "A_Animal.hpp"
# include "Brain.hpp"
class Cat : public A_Animal{
    public:

    Cat();
    Cat(const Cat& src);
    ~Cat();

    Cat& operator=(const Cat& src);

    void makeSound() const;
    

    void setIdea(const std::string& idea, const int it_idea);
    const std::string getIdea(const int it_idea);

    private:
    Brain* _b;
};

#endif