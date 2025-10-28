/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:20:20 by sylabbe           #+#    #+#             */
/*   Updated: 2025/10/28 18:08:43 by sylabbe          ###   ########.fr       */
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

bool strIsDigit(const std::string& str){
    for (size_t i = 0; i != str.size(); i++){
        if (!isdigit(str[i]))
            return (false);
    }
    return (true);
}

bool getDateValue(const std::string& str, long int& n, const size_t& size)
{
    if (str.size() != size || !strIsDigit(str))
        return (false);
    n = strtol(str.c_str(), NULL, 10);
    
    return (true);
}


bool bitcoinExchange::isValidDate(const std::string& date){
    long int year = 0;
    long int month = 0;
    long int day = 0;
    size_t first = date.find_first_of('-');
    size_t last = date.find_last_of('-');

    if (first == std::string::npos ||
        !getDateValue(date.substr(0, first), year, 4) ||
        !getDateValue(date.substr(first + 1, last), month, 2) ||
        !getDateValue(date.substr(last + 1, date.size()), day, 2)){
            std::cout << "1" <<std::endl;
            return (false);
    }
    
    if (year < 1 || (month < 1) || day < 1){//limite max sur year
        std::cout << "2" <<std::endl; 
        return (false);
    }
    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31){
        std::cout << "3" <<std::endl;
        return (false);
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30){
        std::cout << "4" <<std::endl;
        return (false);
    }
    if (year % 4 == 0 && month == 2 && day > 29){
        std::cout << "5" <<std::endl;
        return (false);
    }
    else if (year % 4 != 0 && month == 2 && day > 28)
    {
        std::cout << "6" <<std::endl;
        return (false);
    }
    
    return (true);
}

bool bitcoinExchange::isValidRate(const std::string& rate, double& rateDouble){
    char *end = NULL;
    if (std::count(rate.begin(),rate.end(),'.') > 1)
        return (false);
    for (size_t i = 0; i != rate.size(); i++){
        if (!isdigit(rate[i]) && rate[i] != '.')
            return (false);
    }
    rateDouble = strtod(rate.c_str(), &end);
    if (*end != '\0' || errno == ERANGE)
        return (false);
    return (true);
}


void bitcoinExchange::parseLineDB(const std::string& line){
    std::string date;
    std::string rate;
    size_t comma = line.find_first_of(',');
    double rateDouble = 0;

    if (comma == std::string::npos)//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Retour erreur
        return ;

    date = line.substr(0,comma);
    rate = line.substr(comma + 1, line.size());
    if(!isValidDate(date) || !isValidRate(rate, rateDouble))//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Retour erreur
        return ;
    std::cout << "DATE:" << date << std::endl;
    std::cout << "RATE:" << rate << std::endl;

    _dataBase[date] = rateDouble;
}

void bitcoinExchange::extractDB(const std::string& dbFile){
    std::fstream fs;
    std::string buffer;

    fs.open(dbFile.c_str());
    if (!fs.is_open())
        std::cout << "File did not open" << std::endl;
    while(std::getline(fs,buffer))
        parseLineDB(buffer);
}

bool isValidAmount(const std::string& amount, double& amountDouble){
    char *end = NULL;
    if (std::count(amount.begin(),amount.end(),'.') > 1){
        std::cout << "Error: invalid format of number: " << amount << std::endl;
        return (false);
    }
    for (size_t i = 0; i != amount.size(); i++){
        if (!isdigit(amount[i]) && amount[i] != '.'){
            std::cout << "Error: invalid format of number: " << amount << std::endl;
            return (false);
        }
    }
    amountDouble = strtod(amount.c_str(), &end);
    if (*end != '\0' ){//a voir pas essentiel
        std::cout << "Error: invalid format of number: "  << amount << std::endl;
        return (false);
    }
    if (errno == ERANGE){
        std::cout << "Error: out of bounds number: " << amount << std::endl;
        return (false);
    }
    if (amountDouble > 1000){
        std::cout << "Error: too large a number: " << amount << std::endl;
        return (false);
    }
    if (amountDouble < 0){
        std::cout << "Error: not a positive number: " << amount << std::endl;
        return (false);
    }
    return (true);
}

bool bitcoinExchange::parseLineSearch(const std::string& search){
    std::string date;
    std::string amount;
    double amountDouble;
    if (std::count(search.begin(),search.end(), ' ') != 2 || std::count(search.begin(),search.end(), '|') != 1)
    {
        std::cout << "Error: bad input: " << search << std::endl;
        return (false);
    }
    date = search.substr(0,search.find_first_of(' '));
    amount = search.substr(search.find_last_of(' ') + 1, search.size());
    if (!isValidDate(date)){
        std::cout << "Error: invalid format of date: " << date << std::endl;
        return (false);
    }
    else if (!isValidAmount(amount, amountDouble))
        return (false);
    
    return (true);
}

void bitcoinExchange::printValue(const std::string& search){
    if (!parseLineSearch(search))
        return ;
    
}
