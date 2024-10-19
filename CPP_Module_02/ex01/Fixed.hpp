/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:48:02 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/19 15:20:48 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed{
    public:

    Fixed();
    Fixed(const int n);
    Fixed(const float nf);
    Fixed(const Fixed& other);//Constructeur par copie
    ~Fixed();

    Fixed& operator=(const Fixed& other);//Operateur de copie
    friend std::ostream& operator<<(std::ostream& out, const Fixed& obj);
    
    int getRawBits( void ) const;
    void setRawBits( int const raw );

    float toFloat( void ) const;
    int toInt( void ) const;

    private:
    int fixed_point;
    static const int fractionnal_bits = 8;

};