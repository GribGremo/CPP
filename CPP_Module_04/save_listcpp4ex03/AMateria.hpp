/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:13:31 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/30 16:00:50 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>
// # include "ICharacter.hpp"
class ICharacter;
class AMateria
{
    public:

    AMateria();
    AMateria(std::string const & type);
    AMateria(const AMateria& src);
    virtual ~AMateria();

    virtual AMateria& operator=(const AMateria& src);

    std::string const & getType() const;
    AMateria* getNext() const;
    void setNext(AMateria* m);

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);

    protected:

    std::string type;
    AMateria* next;
};

#endif