/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:36:09 by sylabbe           #+#    #+#             */
/*   Updated: 2025/09/18 16:28:38 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

    #include "Span.hpp"

    Span::Span() : _n(0){    }
    Span::Span(unsigned int n) : _n(n){}
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
    unsigned int Span::shortestSpan(){//Securite 0,1 value
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
    unsigned int Span::longestSpan(){//Securite 0,1 value
        if (_t.size() < 2)
            throw std::exception();
        return (*(--_t.end()) - *_t.begin());
    }

    std::multiset<int>& Span::getT(){
        return (_t);
    }

    