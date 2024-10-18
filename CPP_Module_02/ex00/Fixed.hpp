/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:48:02 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/18 16:57:31 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Fixed{
    public:

    Fixed();
    ~Fixed();

    Fixed(const Fixed& other);//Constructeur par copie
    Fixed& operator=(const Fixed& other);//Operateur de copie

    int getRawBits( void ) const;
    void setRawBits( int const raw );

    private:
    int fixed_point;
    static const int fractionnal_bits = 8;

};