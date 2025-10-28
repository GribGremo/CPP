/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:20:39 by sylabbe           #+#    #+#             */
/*   Updated: 2025/10/27 22:51:49 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char **argv){
    std::fstream fs;
    std::string buffer;

    if (argc != 2)
    {
        std::cout << "Error: Invalid number of arguments" << std::endl;
        return (1);
    }

    bitcoinExchange btc("data.csv");
    fs.open(argv[1]);
    if (!fs.is_open())
        std::cout << "File did not open" << std::endl;
    while(std::getline(fs,buffer))
        btc.printValue(buffer);
}


//Parse file.txt
//  -Format date:Verifier date valide
//  -Value: 0 <= value <= 1000
//Parse data.csv
//Render result (value*rate) from date or lower