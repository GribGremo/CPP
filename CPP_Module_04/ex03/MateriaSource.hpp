/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:45:55 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/05 17:49:40 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"
class MateriaSource : public IMateriaSource
{
    public:
    MateriaSource();
    MateriaSource(const MateriaSource& src);
    ~MateriaSource();

    MateriaSource& operator=(const MateriaSource& src);

    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);

};

#endif