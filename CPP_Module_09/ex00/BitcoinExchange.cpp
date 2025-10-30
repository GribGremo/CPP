/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:20:20 by sylabbe           #+#    #+#             */
/*   Updated: 2025/10/30 08:44:52 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//~~~~~~~~~~~~~~~~~~CONSTRUCTORS~~~~~~~~~~~~~~~~~~

bitcoinExchange::bitcoinExchange(){}

bitcoinExchange::bitcoinExchange(const bitcoinExchange& src) : _dataBase(src._dataBase), _res(src._res){}

bitcoinExchange::bitcoinExchange(std::string dbFile){
    _res.amount = 0;
    _res.total = 0;//A VOIR
    _res.date = "";
    try{
        extractDB(dbFile);
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: Cannot create bitcoinExchange: " << e.what() << std::endl;
        throw;
    }
}

bitcoinExchange::~bitcoinExchange(){}

//~~~~~~~~~~~~~~~~~~OPERATORS~~~~~~~~~~~~~~~~~~

bitcoinExchange& bitcoinExchange::operator=(const bitcoinExchange& src){
    if(this == &src)
        return (*this);
    _dataBase = src._dataBase;
    _res = src._res;
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
    // std::cout << "GETDATEVALUE: " << str << std::endl;
    if (str.size() != size || !strIsDigit(str))
        return (false);
    n = strtol(str.c_str(), NULL, 10);
    
    return (true);
}

bool getSeparator(std::string str, std::string one, std::string two, std::string& sep){
    size_t oneS = str.find(one);
    size_t twoS = str.find(two);

    if (oneS == std::string::npos || twoS == std::string::npos || oneS > twoS)
        return (false);
    sep = str.substr(oneS + one.size(), str.size() - ((oneS +one.size()) + (str.size() - twoS)));
    if (str.size() != (one.size() + two.size() + sep.size()) || sep.empty())
        return (false);

    return (true);
}


bool bitcoinExchange::isValidDate(const std::string& date){
    long int year = 0;
    long int month = 0;
    long int day = 0;
    size_t first = date.find_first_of('-');
    size_t last = date.find_last_of('-');

    if (std::count(date.begin(),date.end(),'-') != 2 ||
        !getDateValue(date.substr(0, first), year, 4) ||
        !getDateValue(date.substr(first + 1, last - (first + 1)), month, 2) ||
        !getDateValue(date.substr(last + 1, date.size() - (last + 1)), day, 2)){
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

bool bitcoinExchange::isValidRate(const std::string& rate, float& ratefloat){
    char *end = NULL;
    if (std::count(rate.begin(),rate.end(),'.') > 1)
        return (false);
    for (size_t i = 0; i != rate.size(); i++){
        if (!isdigit(rate[i]) && rate[i] != '.' && rate[i] != '+' && rate[i] != '-')// attention au + et - dans la string verifie
            return (false);
    }
    ratefloat = strtof(rate.c_str(), &end);
    if (*end != '\0' || errno == ERANGE)
        return (false);
    return (true);
}


void bitcoinExchange::parseLineDB(const std::string& line){
    std::string date;
    std::string rate;
    std::string sep = ",";
    size_t comma = line.find_first_of(sep);// a voir si string
    float ratefloat = 0;

    if (comma == std::string::npos)//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Retour erreur
        throw std::runtime_error("No separator found");

    date = line.substr(0,comma);
    rate = line.substr(comma + 1, comma + 1 - line.size());
    if(!isValidDate(date))//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Retour erreur
        throw std::runtime_error("Invalid date : " + date);
    if(!isValidRate(rate, ratefloat))
        throw std::runtime_error("Invalid rate : " + rate);

    // std::cout << "DATE:" << date << std::endl;
    // std::cout << "RATE:" << rate << std::endl;

    _dataBase[date] = ratefloat;
}

void bitcoinExchange::extractDB(const std::string& dbFile){
    std::fstream fs;
    std::string buffer;
    std::string sep;

    fs.open(dbFile.c_str());
    if (!fs.is_open())
        throw std::runtime_error(dbFile + " did not open");

    std::getline(fs,buffer);
    if (!getSeparator(buffer, "date", "exchange_rate", sep))
        throw std::runtime_error("Invalid header in file '" + dbFile + "' : '" + buffer + "'");

    while(std::getline(fs,buffer))
    {
        try{
            parseLineDB(buffer);
        }
        catch (const std::exception& e)
        {
            fs.close();
            throw ;
        }
    }
    fs.close();
    if (_dataBase.empty())
        throw std::runtime_error("Empty database");

}

bool isValidAmount(const std::string& amount, float& amountfloat){
    char *end = NULL;

    for (size_t i = 0; i != amount.size(); i++){
        if (!isdigit(amount[i]) && amount[i] != '.' && amount[i] != '+' && amount[i] != '-'){
            std::cout << "Error: invalid format of number: " << amount << std::endl;
            return (false);
        }
    }
    amountfloat = strtof(amount.c_str(), &end);
    if (*end != '\0' ){
        std::cout << "Error: invalid format of number: "  << amount << std::endl;
        return (false);
    }
    if (errno == ERANGE){
        std::cout << "Error: out of bounds number: " << amount << std::endl;
        return (false);
    }
    if (amountfloat >= 1000){
        std::cout << "Error: too large a number: " << amount << std::endl;
        return (false);
    }
    if (amountfloat < 0){
        std::cout << "Error: not a positive number: " << amount << std::endl;
        return (false);
    }
    if (amountfloat == 0){
        std::cout << "Error: no need to convert 0: " << amount << std::endl;
        return (false);
    }
    return (true);
}

bool bitcoinExchange::parseLineSearch(const std::string& search, const std::string& sep){
    std::string amount;

    size_t sepS = search.find(sep);

    if (sepS == std::string::npos)
    {
        std::cout << "Error: bad input: " << search << std::endl;
        return (false);
    }
    _res.date = search.substr(0,sepS);
    amount = search.substr(sepS + sep.size(), search.size() - (sepS + sep.size()));
    if (!isValidDate(_res.date)){
        std::cout << "Error: invalid format of date: '" << _res.date << "'" << std::endl;
        return (false);
    }
    else if (!isValidAmount(amount, _res.amount))
        return (false);
    for (std::map<std::string,float>::iterator it = _dataBase.begin(); it != _dataBase.end(); it++)
    {
        if (_res.date < it->first)
            return (true);
        _res.total = _res.amount * it->second;
    }
    return (true);
}

void bitcoinExchange::printValue(const std::string& inputFileName){
    std::fstream fs;
    std::string buffer;
    std::string sep;
    if (_dataBase.empty())
    {
        std::cout << "Error: Database is empty" <<std::endl;
        return ;
    }

    fs.open(inputFileName.c_str());
    if (!fs.is_open()){
        std::cout << "Error: '" << inputFileName << "' did not open" << std::endl;
        return ;
    }
    std::getline(fs,buffer);
    if (!getSeparator(buffer, "date", "value", sep)){
        std::cout << "Error: Invalid header in file '" << inputFileName << "' : '" << buffer << "'" << std::endl;
        return ;
    }
    while(std::getline(fs,buffer)){
        if (parseLineSearch(buffer, sep))
            std::cout<< _res.date << " => " << _res.amount << " = " << _res.total <<std::endl;
    }
    fs.close();
}

//ATTENTION SI TU NE TROUVES PAS DE DATE INFERIEURE
//PAS D'ENTREE DANS LA DB
//Si CONSTRUCTEUR PAR DEFAUT DATABASE PAS INIT SI IL PRINT VALUE
//CPP8 Fais des pointeurs sur tes iterateurs pour verifier la range dans span