/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:13:15 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/18 15:42:50 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

Harl::Harl(){
    fn_cmd[0] = "DEBUG";
    fn_cmd[1] = "INFO";
    fn_cmd[2] = "WARNING";
    fn_cmd[3] = "ERROR";

    fn[0] = &Harl::debug;
    fn[1] = &Harl::info;
    fn[2] = &Harl::warning;
    fn[3] = &Harl::error;
}
Harl::~Harl(){

}
void Harl::complain( std::string level){
    int i = 0;
    while(i < 4 && level != fn_cmd[i])
            i++;

    switch(i + 1){
    case 5:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    case 1:
        (this->*fn[0])();
    case 2:
        (this->*fn[1])();
    case 3:
        (this->*fn[2])();
    case 4:
        (this->*fn[2])();
    }
}
void Harl::debug( void ){
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info( void ){
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning( void ){
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error( void ){
    std::cout <<  "This is unacceptable! I want to speak to the manager now." << std::endl;
}