/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:36:07 by sylabbe           #+#    #+#             */
/*   Updated: 2025/01/30 16:23:15 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template<typename T>
#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>

class Span {
    private:
    unsigned int n;
    T t;

    public:
    Span();
    Span(unsigned int n);
    Span(const Span& src);
    ~Span();

    Span& operator=(const Span& src);

    void addNumber();
    unsigned int shortestSpan();
    unsigned int longestSpan();
};

#endif
