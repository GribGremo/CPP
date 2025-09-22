/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:20:39 by sylabbe           #+#    #+#             */
/*   Updated: 2025/09/22 14:53:59 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char **argv){

    if (argc != 2)
    {
        std::cout << "Invalid number of arguments" << std::endl;
        return (1);
    }
}

void getValues(std::string filename){
    std::fstream fs;
    std::string buffer;
    fs.open(filename);
    if (fs.is_open())
    {
        std::getline(fs,buffer);

    }
    else{
        std::cout << "File did not open" << std::endl;
    }

}

//Parse file.txt
//  -Format date:Verifier date valide
//  -Value: 0 <= value <= 1000
//Parse data.csv
//Render result (value*rate) from date or lower