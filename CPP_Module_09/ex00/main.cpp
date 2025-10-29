/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:20:39 by sylabbe           #+#    #+#             */
/*   Updated: 2025/10/29 10:41:04 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv){
    bitcoinExchange btc;

    if (argc != 2)
    {
        std::cout << "Error: Invalid number of arguments" << std::endl;
        return (1);
    }

    try{
        btc = bitcoinExchange("data.csv");
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: Cannot create bitcoinExchange: " << e.what() << std::endl;
        return (1);
    }

    btc.printValue(argv[1]);
}


//Parse file.txt
//  -Format date:Verifier date valide
//  -Value: 0 <= value <= 1000
//Parse data.csv
//Render result (value*rate) from date or lower