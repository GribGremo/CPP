/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:20:39 by sylabbe           #+#    #+#             */
/*   Updated: 2025/10/30 22:22:47 by grib             ###   ########.fr       */
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

    try
    {
        btc = bitcoinExchange("data.csv");
    }
    catch(const std::exception& e)
    {
        return (1);
    }

    btc.printValue(argv[1]);
    return (0);
}
