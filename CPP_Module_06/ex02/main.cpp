/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:28:25 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/25 20:44:16 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

#include <cstdlib>
#include <ctime> 

Base * generate(void){
    Base* ptr = NULL;
    int r = rand() % 3;
    switch(r) {
        case 0:
            ptr = new A();
            break;
        case 1:
            ptr = new B();
            break;
        case 2:
            ptr = new C();
            break;
    }
    return (ptr);
}

void identify(Base* p){
    if (p == NULL)
        return;
    if(dynamic_cast<A*>(p))
        std::cout << "p is A class type." << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "p is B class type." << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "p is C class type." << std::endl;
    else
        std::cout << "p does not match derived class from Base." << std::endl;
}

void identify(Base& p){    
    try{
        Base& ref = dynamic_cast<A&>(p);
        std::cout << "p is A class type." << std::endl;
        (void)ref;
    }
    catch(...){
        try{
            Base& ref = dynamic_cast<B&>(p);
            std::cout << "p is B class type." << std::endl;
            (void)ref;
        }
        catch(...){
            try{
                Base& ref = dynamic_cast<C&>(p);
                std::cout << "p is C class type." << std::endl;
                (void)ref;
            }
            catch(...){
                std::cout << "p does not match derived class from Base." << std::endl;
            }
        }
    }
}
int main()//fn or methods?
{
    srand(static_cast<unsigned int>(time(NULL))); 

    for(int i = 0; i < 10; i++)
    {
        Base* ptr = generate();
        Base& ref = *ptr;
        identify(ptr);
        identify(ref);
        delete ptr;
        std::cout << std::endl;
    }
}
