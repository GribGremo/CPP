/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:13:12 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/16 16:07:01 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
    Harl harl;
    std::cout<< std::endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
    std::cout  << "CASE DEBUG COMMAND" << std::endl;
    harl.complain("DEBUG");
    std::cout<< std::endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
    std::cout  << "CASE INFO COMMAND" << std::endl;
    harl.complain("INFO");
    std::cout<< std::endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
    std::cout  << "CASE WARNING COMMAND" << std::endl;
    harl.complain("WARNING");
    std::cout<< std::endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
    std::cout  << "CASE ERROR COMMAND" << std::endl;
    harl.complain("ERROR");
    std::cout<< std::endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
    std::cout  << "CASE *UNKNOWN* COMMAND" << std::endl;
    harl.complain("UNKNOWN");
    std::cout<< std::endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
    std::cout  << "CASE NULL COMMAND" << std::endl;
    harl.complain(NULL);
    std::cout << std::endl;

    return 0;
}