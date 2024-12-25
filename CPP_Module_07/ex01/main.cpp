/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 23:02:13 by sylabbe           #+#    #+#             */
/*   Updated: 2024/12/25 23:47:29 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"



int main(){
    std::string str = "123456789";
    int t[] = {0,1,2,3,4,5,6,7,8,9};

    iter(t,10,incr<int>);// You need to specify the type of incr at this type, or he doesnt know the type of that function, he can take whatever but need to know at least

    for(int i = 0; i<10;i++){
        std::cout << "Value " << i << " of array: " << t[i] << std::endl;
    }
    std::cout << std::endl;
    // iter(t,10,square<float>);//Cannot do this my array is int type, can/t put float in it
    iter(t,10,square<int>);
    
    for(int i = 0; i<10;i++){
        std::cout << "Value " << i << " of array: " << t[i] << std::endl;
    }
}