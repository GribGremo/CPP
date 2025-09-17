/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 10:49:22 by sylabbe           #+#    #+#             */
/*   Updated: 2025/09/12 16:47:31 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP
# define VECT2_HPP

# include <iostream>

class Vect2 {

    public:

    Vect2();
    Vect2(const int n1, const int n2);
    Vect2(const Vect2& v);
    ~Vect2();

    Vect2& operator=(const Vect2& v);//Copy
    
    //arythmetic operators

    Vect2 operator+(const Vect2& v)const;
    Vect2 operator-(const Vect2& v)const;
    Vect2 operator*(const Vect2& v)const;

    Vect2 operator+(int n)const;
    Vect2 operator-(int n) const;
    Vect2 operator*(int n)const;

    //location operator
    int& operator[](int i);
    const int& operator[](int i) const;

    //incremental/decremental operators
    Vect2& operator++();// Avant ou apres
    Vect2 operator++(int n);
    Vect2& operator--();
    Vect2 operator--(int n);

    Vect2& operator+=(int n);
    Vect2& operator-=(int n);
    Vect2& operator*=(const int n);
    

    Vect2& operator+=(const Vect2& v);
    Vect2& operator-=(const Vect2& v);
    Vect2& operator*=(const Vect2& v);

    //comparison operators
    bool operator==(const Vect2& v)const;
    bool operator!=(const Vect2& v)const;

    //unary operator
    Vect2 operator-()const;

    //getters
    int getNone()const;
    int getNtwo()const;

    void setNone(int n);
    void setNtwo(int n);


    private:

    int _n1;
    int _n2;
};

//stream operator
std::ostream& operator<<(std::ostream& os, const Vect2& v);

//arythmetic opertors
Vect2 operator*(int n, const Vect2& v);
Vect2 operator+(int n, const Vect2& v);//Pas sur de devoir les inclure
Vect2 operator-(int n, const Vect2& v);//

#endif