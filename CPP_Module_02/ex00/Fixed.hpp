/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:48:02 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/22 10:48:55 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Fixed{
    public:

    Fixed();
    ~Fixed();

    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);

    int getRawBits( void ) const;
    void setRawBits( int const raw );

    private:
    int fixed_point;
    static const int fractionnal_bits = 8;

};