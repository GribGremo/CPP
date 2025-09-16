/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 23:02:13 by sylabbe           #+#    #+#             */
/*   Updated: 2025/09/15 14:32:36 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void incrChar(char& c){
    ++c;
}

int main(){
    std::string str = "123456789";
    int t[] = {0,1,2,3,4,5,6,7,8,9};

    std::cout << "PRE-INCR:" <<std::endl;
    iter(t,10,printCell<int>);
    std::cout << std::endl;

    iter(t,10,incr<int>);// You need to specify the type of incr at this type, or he doesnt know the type of that function, he can take whatever but need to know at least
   
    std::cout << "POST-INCR:" <<std::endl;
    iter(t,10,printCell<int>);
    std::cout << std::endl;

    // iter(t,10,square<float>);//Cannot do this my array is int type, can't put float in it
    iter(t,10,square<int>);

    std::cout << "POST-SQUARE:" <<std::endl;
    iter(t,10,printCell<int>);
    std::cout << std::endl;
    
    iter(&str[0],str.size(),incr<char>);// I change address from reference to pointer so he can accept rvalue
    std::cout <<"str: "<< str << std::endl;
    std::cout << std::endl;

    iter(&str[0],str.size(),incrChar);
    std::cout << "str: " << str << std::endl;
    std::cout << std::endl;

    iter(static_cast<char*>(NULL),1,incrChar);
    iter(t,0,printCell<int>);//Loop 0 times nothing happen
    iter(t,-1,printCell<int>);
    //iter(t,1,NULL); Herer compilator will issue a warning
}
