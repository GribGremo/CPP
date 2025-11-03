/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:20:39 by sylabbe           #+#    #+#             */
/*   Updated: 2025/11/03 15:21:38 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

#define DATAFILE "data.csv"

int main(int argc, char **argv){
    bitcoinExchange btc;

    if (argc != 2)
    {
        std::cout << "Error: Invalid number of arguments" << std::endl;
        return (1);
    }

    try
    {
        btc = bitcoinExchange(DATAFILE);
    }
    catch(const std::exception& e)
    {
        return (1);
    }
    
    std::cout << "~~~~~~~~~~~~~~~Main Test~~~~~~~~~~~~~~~" <<std::endl;
    btc.printValue(argv[1]);
    std::cout << std::endl;
    
    std::cout << "~~~~~~~~~~~~~~~operator= Test~~~~~~~~~~~~~~~" <<std::endl;
    bitcoinExchange test = btc;
    test.printValue(argv[1]);
    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~~~~~Copy constructor Test~~~~~~~~~~~~~~~" <<std::endl;
    bitcoinExchange test2(btc);
    test2.printValue(argv[1]);

    return (0);
}
