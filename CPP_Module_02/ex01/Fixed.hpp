/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:48:02 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/23 15:56:09 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed{
    public:

    Fixed();
    Fixed(const int n);
    Fixed(const float nf);
    Fixed(const Fixed& other);//Constructeur par copie
    ~Fixed();

    Fixed& operator=(const Fixed& other);//Operateur de copie
    
    int getRawBits( void ) const;
    void setRawBits( int const raw );

    float toFloat( void ) const;
    int toInt( void ) const;

    private:
    int fixed_point;
    static const int fractionnal_bits = 8;

};

std::ostream& operator<<(std::ostream& out, const Fixed& src);

#endif