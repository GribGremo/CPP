/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:13:31 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/05 16:28:34 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>
# include "ICharacter.hpp"
class AMateria
{
    public:

    AMateria();
    AMateria(std::string const & type);
    AMateria(const AMateria& src);
    ~AMateria();

    AMateria& operator=(const AMateria& src);

    std::string const & getType() const;

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);

    protected:

    std::string type;

};

#endif