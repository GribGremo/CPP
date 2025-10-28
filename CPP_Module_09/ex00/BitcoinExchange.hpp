/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:20:32 by sylabbe           #+#    #+#             */
/*   Updated: 2025/10/28 00:20:57 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>
#include <string>
#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

class bitcoinExchange
{
    //~~~~~~~~~~~~~~~~~~METHODS~~~~~~~~~~~~~~~~~~
    private:
    bool isValidDate(std::string date);
    void parseLineDB(std::string line);
    void extractDB(std::string dbFile);

    public:
    void printValue(const std::string& search);

    //~~~~~~~~~~~~~~~~~~MEMBERS~~~~~~~~~~~~~~~~~~
    std::map<std::string,std::string> _dataBase;

    public:
    bitcoinExchange();
    bitcoinExchange(const bitcoinExchange& src);
    bitcoinExchange(std::string dbFile);
    ~bitcoinExchange();

    bitcoinExchange& operator=(const bitcoinExchange& src);

};

#endif