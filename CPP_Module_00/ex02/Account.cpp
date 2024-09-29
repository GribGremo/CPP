/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:18:21 by sylabbe           #+#    #+#             */
/*   Updated: 2024/09/18 17:57:57 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>

#include "Account.hpp"

    #define BLUE "\033[36m"
    
    void print_color(std::string color, int nbr);

    int Account::_nbAccounts = 0;
    int Account::_totalAmount = 0;
    int Account::_totalNbDeposits = 0;
    int Account::_totalNbWithdrawals = 0;



	////////////////////CONSTRUCTORS////////////////////
	Account::Account( void ){
        _accountIndex = 0;
	    _amount = 0;
	    _nbDeposits = 0;
	    _nbWithdrawals = 0;

    }

	Account::Account( int initial_deposit ){
        _accountIndex = _nbAccounts;
	    _nbDeposits = 0;
	    _nbWithdrawals = 0;
        _amount = initial_deposit;

        _nbAccounts++;
        _totalAmount = _totalAmount + initial_deposit;

        _displayTimestamp();
        std::cout << "index:";  print_color(BLUE,_accountIndex);
        std::cout <<";amount:"; print_color(BLUE,initial_deposit);
        std::cout <<";created" << std::endl;
    }
	Account::~Account( void ){
        _displayTimestamp();
        std::cout << "index:";  print_color(BLUE,_accountIndex);std::cout << ";";
        std::cout << "amount:";  print_color(BLUE,_amount);std::cout << ";closed" << std::endl;
    }

	////////////////////GETTERS////////////////////
	int	Account::getNbAccounts( void ){
        return(_nbAccounts);
    }

	int	Account::getTotalAmount( void ){
        return(_totalAmount);
    }

	int	Account::getNbDeposits( void ){
        return(_totalNbDeposits);
    }
    
	int	Account::getNbWithdrawals( void ){
        return(_totalNbWithdrawals);
    }

    ////////////////////DISPLAYFUNCTIONS////////////////////
	void	Account::displayAccountsInfos( void ){
        _displayTimestamp();
        std::cout << "accounts:";  print_color(BLUE,_nbAccounts);std::cout << ";";
        std::cout << "total:";  print_color(BLUE,_totalAmount);std::cout << ";";
        std::cout << "deposits:";  print_color(BLUE,_totalNbDeposits);std::cout << ";";
        std::cout << "withdrawals:";  print_color(BLUE,_totalNbWithdrawals);std::cout << std::endl;
    }

	void	Account::_displayTimestamp( void ){ 
    std::time_t currentTime = std::time(0);
    std::tm* localTime = std::localtime(&currentTime);

    std::cout <<"[";
    std::cout <<(localTime->tm_year + 1900);
    std::cout <<(localTime->tm_mon + 1);
    std::cout << localTime->tm_mday;
    std::cout <<"_";
    std::cout << localTime->tm_hour;
    std::cout << localTime->tm_min;
    std::cout << localTime->tm_sec;
    std::cout <<"] ";
    }

    ////////////////////ACTIONSFUNCTIONS////////////////////
   	void	Account::makeDeposit( int deposit ){
        _displayTimestamp();
        std::cout << "index:";  print_color(BLUE,_accountIndex);std::cout << ";";
        std::cout << "p_amount:";  print_color(BLUE,_amount);std::cout << ";";
        std::cout << "deposit:";  print_color(BLUE,deposit);std::cout << ";";
        _amount = _amount + deposit;
        _totalAmount = _totalAmount + deposit;
        std::cout << "amount:";  print_color(BLUE,_amount);std::cout << ";";
        _nbDeposits++;
        _totalNbDeposits++;
        std::cout << "nb_deposits:";  print_color(BLUE,_nbDeposits);std::cout << std::endl;
    }

	bool	Account::makeWithdrawal( int withdrawal ){
        _displayTimestamp();
        std::cout << "index:";  print_color(BLUE,_accountIndex);std::cout << ";";
        std::cout << "p_amount:";  print_color(BLUE,_amount);std::cout << ";";
        if (_amount - withdrawal >= 0)
        {
            std::cout << "withdrawal:";  print_color(BLUE,withdrawal);std::cout << ";";
            _amount = _amount - withdrawal;
            _totalAmount = _totalAmount - withdrawal;
            std::cout << "amount:";  print_color(BLUE,_amount);std::cout << ";";
            _nbWithdrawals++;
            _totalNbWithdrawals++;
            std::cout << "nb_withdrawals:";  print_color(BLUE,_nbWithdrawals);std::cout << std::endl;
            return (true);
        }
        else
        {
            std::cout << "withdrawal:refused" << std::endl;
            return (false);
        }
    }

	int		Account::checkAmount( void ) const{
        return(_amount);
    }

	void	Account::displayStatus( void ) const{
        _displayTimestamp();
        std::cout << "index:";  print_color(BLUE,_accountIndex);std::cout << ";";
        std::cout << "total:";  print_color(BLUE,_amount);std::cout << ";";
        std::cout << "deposits:";  print_color(BLUE,_nbDeposits);std::cout << ";";
        std::cout << "withdrawals:";  print_color(BLUE,_nbWithdrawals);std::cout << std::endl;;
    }

    void print_color(std::string color, int nbr)
    {
        std::cout<< color << nbr << "\033[0m";
    }