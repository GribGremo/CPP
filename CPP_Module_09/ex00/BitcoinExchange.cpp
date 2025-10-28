/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:20:20 by sylabbe           #+#    #+#             */
/*   Updated: 2025/10/28 00:23:25 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//~~~~~~~~~~~~~~~~~~CONSTRUCTORS~~~~~~~~~~~~~~~~~~

bitcoinExchange::bitcoinExchange(){}

bitcoinExchange::bitcoinExchange(const bitcoinExchange& src) : _dataBase(src._dataBase){}

bitcoinExchange::bitcoinExchange(std::string dbFile){
    extractDB(dbFile);
}

bitcoinExchange::~bitcoinExchange(){}

//~~~~~~~~~~~~~~~~~~OPERATORS~~~~~~~~~~~~~~~~~~

bitcoinExchange& bitcoinExchange::operator=(const bitcoinExchange& src){
    if(this == &src)
        return (*this);
    _dataBase = src._dataBase;
    return (*this);
}

//~~~~~~~~~~~~~~~~~~METHODS~~~~~~~~~~~~~~~~~~

bool isFormatInt(const std::string& str, int& n)
{
    char *end = NULL;
    n = strtol(str.c_str(), &end, 10);
    if (errno == ERANGE || *end != '\0')
        return (false);
    return (true);
}


bool bitcoinExchange::isValidDate(std::string date){
    int year = 0;
    int month = 0;
    int day = 0;
    size_t first = date.find_first_of('-');
    size_t last = date.find_last_of('-');

    year = stoi(date.substr(0,first - 1));
    month = stoi(date.substr(first + 1, last - 1));
    day = stoi(date.substr(last + 1, date.size()));

}

void bitcoinExchange::isValidRate(std::string rate){

}


void bitcoinExchange::parseLineDB(std::string line){
    std::string date;
    std::string rate;
    size_t comma = line.find_first_of(',');
    if (comma == std::string::npos)//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Retour erreur
        return ;

    date = line.substr(0,comma - 1);
    rate = line.substr(comma + 1, line.size());
    if(!isValidDate(date) || !isValidRate(rate))//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Retour erreur
        return ;
    std::cout << "DATE:" << date << std::endl;
    std::cout << "RATE:" << rate << std::endl;

    _dataBase[date] = rate;

}

void bitcoinExchange::extractDB(std::string dbFile){

}
void bitcoinExchange::printValue(const std::string& search){

}
