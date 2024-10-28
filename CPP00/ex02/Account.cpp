/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:15:48 by fli               #+#    #+#             */
/*   Updated: 2024/10/28 18:47:06 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int	Account::_nbAccounts = -1;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts()
{
	return(_nbAccounts);
}

int	Account::getTotalAmount()
{
	return(_totalAmount);
}

int	Account::getNbDeposits()
{
	return(_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
	return(_totalNbWithdrawals);
}

void	Account::_displayTimestamp()
{
	std::time_t currentTime = std::time(NULL);
	std::tm *localTime = std::localtime(&currentTime);
	std::cout	<< "[" << (localTime->tm_year + 1900)
				<< (localTime->tm_mon + 1)
				<< localTime->tm_mday
				<< "_"
				<< localTime->tm_hour
				<< localTime->tm_min
				<< localTime->tm_sec
				<< "]";
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << " accounts:" << (getNbAccounts() + 1);
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
}

Account::Account( int initial_deposit )
{
	this->_amount = initial_deposit;
	this->_totalAmount = this->_totalAmount + initial_deposit;
	_nbAccounts++;
	_accountIndex = getNbAccounts();
	_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";amount:" << initial_deposit << ";created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	this->_nbDeposits++;
	this->_amount = this->_amount + deposit;
	this->_totalAmount = this->_totalAmount + deposit;
	this->_totalNbDeposits++;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	if (this->_amount - withdrawal < 0)
	{
		std::cout << ";withdrawal:refused";
		std::cout << std::endl;
		return (false);
	}
	else
	{
		this->_nbWithdrawals++;
		this->_totalNbWithdrawals++;
		std::cout << ";withdrawal:" << withdrawal;
		this->_amount = this->_amount - withdrawal;
		this->_totalAmount = this->_totalAmount - withdrawal;
		std::cout << ";amount:" << _amount;
		std::cout << ";nb_withdrawals:" << _nbWithdrawals;
		std::cout << std::endl;
		return (true);
	}
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
}
