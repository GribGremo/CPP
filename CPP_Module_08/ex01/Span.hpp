/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:36:07 by sylabbe           #+#    #+#             */
/*   Updated: 2025/09/18 21:25:12 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>

#include <set>
#include <vector>

// template <typename IT>
class Span {
    private:
    unsigned int _n;
    std::multiset<int> _t;

    public:
    Span();
    Span(unsigned int n);
    Span(const Span& src);
    ~Span();

    Span& operator=(const Span& src);

    void addNumber(int value);
    unsigned int shortestSpan();
    unsigned int longestSpan();
    void fillT(std::vector<int>::iterator& begin,std::vector<int>::iterator& end);

    std::multiset<int>& getT();
};


#endif
