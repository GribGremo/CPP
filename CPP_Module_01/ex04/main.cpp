/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:12:05 by sylabbe           #+#    #+#             */
/*   Updated: 2024/09/28 17:48:38 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <fstream>

int main(int argc, char **argv)
{
    std::fstream fs;
    std::string line;


    fs.open(argv[1],std::fstream::in);
    if (!fs.is_open())
    {
        std::cout << "Cannot open file" << argv[1] << std::endl;
        return (1);
    }
    
    while (std::getline(fs, line)) {
        std::cout << line << std::endl; // Affichage de chaque ligne
    }
    fs.close();
}
