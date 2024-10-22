/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:48:02 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/22 11:58:45 by sylabbe          ###   ########.fr       */
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

    bool operator<(const Fixed& other);
    bool operator>(const Fixed& other);
    bool operator<=(const Fixed& other);
    bool operator>=(const Fixed& other);
    bool operator==(const Fixed& other);
    bool operator!=(const Fixed& other);

    Fixed operator+(const Fixed& other);
    Fixed operator-(const Fixed& other);
    Fixed operator*(const Fixed& other);
    Fixed operator/(const Fixed& other);

    Fixed& operator++();
    Fixed& operator--();
    Fixed operator++(int);
    Fixed operator--(int);
    Fixed& operator=(const Fixed& other);//Operateur de copie
    std::ostream& operator<<(std::ostream& out);
    
    static Fixed& max(Fixed& a, Fixed& b);
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);


    int getRawBits( void ) const;
    void setRawBits( int const raw );

    float toFloat( void ) const;
    int toInt( void ) const;

    private:
    int fixed_point;
    static const int fractionnal_bits = 8;

};