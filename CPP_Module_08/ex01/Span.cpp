/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:36:09 by sylabbe           #+#    #+#             */
/*   Updated: 2025/09/19 21:31:21 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

    #include "Span.hpp"

    Span::Span() : _n(0){
    }
    Span::Span(int n){
        if (n < 0)
            _n = -n;
        else
            _n = n;
    }
    Span::Span(const Span& src): _n(src._n){
        this->_t =src._t;
    }
    Span::~Span(){}

    Span& Span::operator=(const Span& src){
        _n = src._n;
        this->_t.clear();
        this->_t =src._t;
        return (*this);
    }

    void Span::addNumber(int value){
        if (_t.size() >= _n)
            throw (std::exception());
        else
            _t.insert(value);
    }
    unsigned int Span::shortestSpan(){
        if (_t.size() < 2)
            throw std::exception();
        unsigned int r = 4294967295;
        std::multiset<int>::iterator it = _t.begin();

        for (std::multiset<int>::iterator next = ++_t.begin(); next != _t.end(); ++next)
        {
            if ((unsigned int)(*next - *it) < r)
                r = *next -*it;
            it = next;
        }
        return (r);
    }
    unsigned int Span::longestSpan(){
        if (_t.size() < 2)
            throw std::exception();
        return (*(--_t.end()) - *_t.begin());
    }

    void Span::fillT(std::vector<int>::iterator& begin,std::vector<int>::iterator& end){
        unsigned int s_fill = 0;
        unsigned int a_space = _n - _t.size();
        if (begin > end)
            return;
        for (std::vector<int>::iterator it = begin;it != end;it++)
            s_fill++;
        if(a_space >= s_fill)
            _t.insert(begin,end);
        else{
            _t.insert(begin, begin + a_space); 
            throw std::exception();
        }
    }
    
    void Span::printContainer(){
        std::cout << "~~~~~~~~~~~~~~~PRINT CONTAINER~~~~~~~~~~~~~~~" << std::endl;
        for (std::multiset<int>::iterator it = _t.begin(); it != _t.end(); it++)
            std::cout << *it << std::endl;
        std::cout << std::endl;
    }

    std::multiset<int>& Span::getT(){
        return (_t);
    }

    