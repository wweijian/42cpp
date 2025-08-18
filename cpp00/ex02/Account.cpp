/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:13:35 by weijian           #+#    #+#             */
/*   Updated: 2025/08/18 13:22:03 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

// Initialization
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// Constructor 
Account::Account(int initial_deposit)
	:	_accountIndex(_nbAccounts),
		_amount(initial_deposit),
		_nbDeposits(0),
		_nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:"<< _accountIndex << ";amount:" << _amount << ";created" << std::endl;
	return ;
}

Account::~Account()
{
	_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:"<< _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
	return ;
}

// Getters
int		Account::getNbAccounts()
{
	return (_nbAccounts);
}
int		Account::getTotalAmount()
{
	return (_totalAmount);
}
int		Account::getNbDeposits()
{
	return(_totalNbDeposits);
}
int		Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}
void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit << ";amount:" << (_amount += deposit);
	std::cout << ";nb_deposits:" << ++_nbDeposits;
	_totalAmount += deposit;
	std::cout << std::endl;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	std::cout << ";withdrawal:";
	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal << ";amount:" << (_amount -= withdrawal);
	std::cout << ";nb_deposits:" << ++_nbWithdrawals;
	std::cout << std::endl;
	_totalAmount -= withdrawal;
	return (true);
}
int		Account::checkAmount() const
{
	return(_amount);
}
void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits << ";withdrawal:" << _nbWithdrawals;
	std::cout << std::endl;
}

// Utils
void	Account::_displayTimestamp( void )
{
	struct tm	*dateTime;
	std::time_t	rawTime = std::time(nullptr) ;

	dateTime = std::localtime(&rawTime);
	std::cout << '[' << dateTime->tm_year + 1900;
	std::cout << dateTime->tm_mon;
	std::cout << dateTime->tm_mday;
	std::cout << '_';
	std::cout << dateTime->tm_hour;
	std::cout << dateTime->tm_min;
	std::cout << dateTime->tm_sec;
	std::cout << "] ";
}

