/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:04:37 by fli               #+#    #+#             */
/*   Updated: 2024/11/21 18:29:52 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

class BitcoinExchange::InvalidFile : public std::exception
{
	public :
	const char* what() const throw()
	{
		return "error : fail to process file";
	}
};

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _database(other._database)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->_database = other._database;
	}
	return *this;
}

BitcoinExchange::BitcoinExchange(std::string filename)
{
	std::ifstream	inputFile(filename);
	if (!inputFile.is_open())
	{
		throw InvalidFile();
	}
}

bool	BitcoinExchange::checkline(std::string line)
{
	int i = 0;

	while (i < 10)
	{
		if ((i == 5 || i == 7) && line[i] != '-')
			return false;
		else if (!isdigit(line[i]))
			return false;
		i++;
	}
	if (line[i++] != ' ' || line[i++] != '|' || line[i++] != ' ')
		return false;
	long long value = std::atof(&line[i]);
	if (value < 0 || value > 1000)
		return false;
	return true;
}
