/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:20:32 by sylabbe           #+#    #+#             */
/*   Updated: 2025/10/28 17:54:53 by sylabbe          ###   ########.fr       */
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
    //extract DB
    bool isValidDate(const std::string& date);
    bool isValidRate(const std::string& rate, double& rateDouble);

    void parseLineDB(const std::string& line);
    void extractDB(const std::string& dbFile);

    //print value
    bool parseLineSearch(const std::string& search);

    public:
    void printValue(const std::string& search);

    //~~~~~~~~~~~~~~~~~~MEMBERS~~~~~~~~~~~~~~~~~~
    private:
    std::map<std::string,double> _dataBase;

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