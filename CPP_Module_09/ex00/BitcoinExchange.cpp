/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:20:20 by sylabbe           #+#    #+#             */
/*   Updated: 2025/11/03 15:10:41 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//~~~~~~~~~~~~~~~~~~CONSTRUCTORS~~~~~~~~~~~~~~~~~~

bitcoinExchange::bitcoinExchange(){}

bitcoinExchange::bitcoinExchange(const bitcoinExchange& src) : _dataBase(src._dataBase), _res(src._res){}

bitcoinExchange::bitcoinExchange(std::string dbFile){
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

bool bitcoinExchange::strIsDigit(const std::string& str){
    for (size_t i = 0; i != str.size(); i++){
        if (!isdigit(str[i]))
            return (false);
    }
    return (true);
}

bool bitcoinExchange::getDateValue(const std::string& str, long int& n, const size_t& size)
{
    if (str.size() != size || !strIsDigit(str))
        return (false);
    n = strtol(str.c_str(), NULL, 10);
    
    return (true);
}

bool bitcoinExchange::getSeparator(std::string str, std::string one, std::string two, std::string& sep){
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
        !getDateValue(date.substr(last + 1, date.size() - (last + 1)), day, 2))
            return (false);

    if (year < 1 || (month < 1 || month > 12) || day < 1)
        return (false);
    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
        return (false);
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return (false);
    if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month == 2 && day > 29)
        return (false);
    else if (!((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month == 2 && day > 28)
        return (false);

    return (true);
}

bool bitcoinExchange::isValidRate(const std::string& rate, double& ratedouble){
    char *end = NULL;

    if (std::count(rate.begin(),rate.end(),'.') > 1)
        return (false);
    for (size_t i = 0; i != rate.size(); i++){
        if (!isdigit(rate[i]) && rate[i] != '.' && rate[i] != '+' && rate[i] != '-')
            return (false);
    }
    ratedouble = strtod(rate.c_str(), &end);
    if (*end != '\0' || errno == ERANGE || ratedouble < 0)
        return (false);
    return (true);
}


void bitcoinExchange::parseLineDB(const std::string& line, std::string sep)
{
    std::string date;
    std::string rate;
    size_t sepS = line.find(sep);
    double ratedouble = 0;

    if (sepS == std::string::npos)
        throw std::runtime_error("No separator found");

    date = line.substr(0,sepS);
    rate = line.substr(sepS + sep.size(), line.size() - (sepS + sep.size()));

    if(!isValidDate(date))
        throw std::runtime_error("Invalid date : " + date);
    if(!isValidRate(rate, ratedouble))
        throw std::runtime_error("Invalid rate : " + rate);
    if (_dataBase.find(date) != _dataBase.end() && _dataBase.find(date)->second != ratedouble)
        throw std::runtime_error("Two entries for day " + date + " have different rate");

    _dataBase[date] = ratedouble;
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
            parseLineDB(buffer,sep);
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

bool bitcoinExchange::isValidAmount(const std::string& amount, double& amountdouble){
    char *end = NULL;

    for (size_t i = 0; i != amount.size(); i++){
        if (!isdigit(amount[i]) && amount[i] != '.' && amount[i] != '+' && amount[i] != '-'){
            std::cout << "Error: invalid format of number: " << amount << std::endl;
            return (false);
        }
    }
    amountdouble = strtod(amount.c_str(), &end);
    if (*end != '\0' ){
        std::cout << "Error: invalid format of number: "  << amount << std::endl;
        return (false);
    }
    if (errno == ERANGE){
        std::cout << "Error: out of bounds number: " << amount << std::endl;
        return (false);
    }
    if (amountdouble >= 1000){
        std::cout << "Error: too large a number: " << amount << std::endl;
        return (false);
    }
    if (amountdouble < 0){
        std::cout << "Error: not a positive number: " << amount << std::endl;
        return (false);
    }
    if (amountdouble == 0){
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
    if (_res.date < _dataBase.begin()->first)
    {
        std::cout << "Error: No rate anterior to " << _res.date <<std::endl;
        return (false);       
    }
    for (std::map<std::string,double>::iterator it = _dataBase.begin(); it != _dataBase.end(); it++)
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
        fs.close();
        return ;
    }
    while(std::getline(fs,buffer)){
        _res.amount = 0;
        _res.total = -1;
        _res.date = "";
        if (parseLineSearch(buffer, sep)){
            if (std::isinf(_res.total))
                std::cout << "Error: Value too big(i really should have invested)" <<std::endl;
            else
                std::cout<< _res.date << " => " << _res.amount << " = " << std::fixed  << std::setprecision(2) << _res.total <<std::endl;
        }
    }
    fs.close();
}
