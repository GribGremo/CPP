/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:20:32 by sylabbe           #+#    #+#             */
/*   Updated: 2025/11/03 14:45:19 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <algorithm>
#include <climits>
#include <map>
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

class bitcoinExchange
{
    //~~~~~~~~~~~~~~~~~~STRUCTURES~~~~~~~~~~~~~~~~~~
    private:
    struct result{
        double amount;
        double total;
        std::string date;
    };

    //~~~~~~~~~~~~~~~~~~METHODS~~~~~~~~~~~~~~~~~~
    private:
    //utils
    bool getSeparator(std::string str, std::string one, std::string two, std::string& sep);
    bool getDateValue(const std::string& str, long int& n, const size_t& size);
    bool strIsDigit(const std::string& str);


    //extract DB
    bool isValidDate(const std::string& date);
    bool isValidRate(const std::string& rate, double& ratedouble);
    void parseLineDB(const std::string& line, std::string sep);
    void extractDB(const std::string& dbFile);

    //print value
    bool isValidAmount(const std::string& amount, double& amountdouble);
    bool parseLineSearch(const std::string& search, const std::string& sep);

    public:
    void printValue(const std::string& search);

    //~~~~~~~~~~~~~~~~~~MEMBERS~~~~~~~~~~~~~~~~~~
    private:
    std::map<std::string,double> _dataBase;
    result _res;

    //~~~~~~~~~~~~~~~~~~CONSTRUCTORS~~~~~~~~~~~~~~~~~~
    public:
    bitcoinExchange();
    bitcoinExchange(const bitcoinExchange& src);
    bitcoinExchange(std::string dbFile);
    ~bitcoinExchange();

    //~~~~~~~~~~~~~~~~~~OPERATORS~~~~~~~~~~~~~~~~~~
    public:
    bitcoinExchange& operator=(const bitcoinExchange& src);

};

#endif