/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:36:09 by sylabbe           #+#    #+#             */
/*   Updated: 2025/01/30 17:35:58 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

    Span::Span(){

    }
    Span::Span(int n){
        this->n = n;
        T<int>(n);
    }
    Span::Span(const Span& src){
        this->T = T;
    }
    Span::~Span(){

    }

    Span& Span::operator=(const Span& src){
        this->T = T;
    }

    void Span::addNumber(){
        
    }
    unsigned int Span::shortestSpan(){

    }
    unsigned int Span::longestSpan(){

    }