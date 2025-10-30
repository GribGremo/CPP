/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:20:32 by sylabbe           #+#    #+#             */
/*   Updated: 2025/10/30 15:46:03 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <algorithm>
#include <climits>
#include <map>
#include <iostream>
#include <string>

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

class bitcoinExchange
{
    //~~~~~~~~~~~~~~~~~~METHODS~~~~~~~~~~~~~~~~~~
    private:
    struct result{
        float amount;
        float total;
        std::string date;
    };

    //~~~~~~~~~~~~~~~~~~METHODS~~~~~~~~~~~~~~~~~~
    private:
    //extract DB
    bool isValidDate(const std::string& date);
    bool isValidRate(const std::string& rate, float& ratefloat);

    void parseLineDB(const std::string& line, std::string sep);
    void extractDB(const std::string& dbFile);

    //print value
    bool parseLineSearch(const std::string& search, const std::string& sep);

    public:
    void printValue(const std::string& search);

    //~~~~~~~~~~~~~~~~~~MEMBERS~~~~~~~~~~~~~~~~~~
    private:
    std::map<std::string,float> _dataBase;
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