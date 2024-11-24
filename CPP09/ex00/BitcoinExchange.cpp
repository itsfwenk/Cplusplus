/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:04:37 by fli               #+#    #+#             */
/*   Updated: 2024/11/24 13:58:48 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

class BitcoinExchange::CannotOpenFile : public std::exception
{
	public :
	const char* what() const throw()
	{
		return "error : could not open file.";
	}
};

class BitcoinExchange::BadInput : public std::exception
{
	public :
	const char* what() const throw()
	{
		return "error : bad input";
	}
};

class BitcoinExchange::TooLargeNumber : public std::exception
{
	public :
	const char* what() const throw()
	{
		return "error : too large number.";
	}
};

class BitcoinExchange::NotPositiveNumber : public std::exception
{
	public :
	const char* what() const throw()
	{
		return "error : not a positive number.";
	}
};

BitcoinExchange::BitcoinExchange()
{
	std::ifstream	dbFile("data.csv");
	if (!dbFile.is_open())
		throw CannotOpenFile();
	std::string line;
	while(std::getline(dbFile, line))
	{
		this->_database.insert(std::make_pair(line.substr(0, 10), std::atof(line.substr(11).c_str())));
	}
	dbFile.close();
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

void	BitcoinExchange::checkline(std::string line)
{
	size_t i = 0;

	while (i < 10)
	{
		if ((i == 4 || i == 7) && line[i] != '-')
			throw BadInput();
		else if ((i != 4 && i != 7) && !isdigit(line[i]))
			throw BadInput();
		i++;
	}
	if (i + 3 < line.length() && (line[i++] != ' ' || line[i++] != '|' || line[i++] != ' '))
		throw BadInput();
	size_t first = i;
	while (i < line.length())
	{
		if (i == first && !isdigit(line[i]) && line[i] != '-' && line[i] != '+')
			throw BadInput();
		else if (i != first && !isdigit(line[i]) && line[i] != '.')
			throw BadInput();
		i++;
	}
}

// BitcoinExchange::BitcoinExchange()
// {
// 	std::ifstream	inputFile(filename);
// 	if (!inputFile.is_open())
// 	{
// 		throw InvalidFile();
// 	}
// 	std::string line;
// 	// std::map<std::string, double>::iterator it = this->_database.begin();
// 	while(std::getline(inputFile, line))
// 	{
// 		BitcoinExchange::checkline(line);
// 			throw InvalidFile();
// 		std::pair<std::map<std::string, double>::iterator, bool> result;
// 		result = this->_database.insert(std::make_pair(line.substr(0, 10), std::atof(line.substr(13).c_str())));
// 		if (!result.second)
// 			throw InvalidFile();
// 		// database[line.substr(0, 10)] = std::atof(line.substr(13).c_str());
// 	}
// 	inputFile.close();
// }



// struct tm time;
// !strptime(result.first->first.c_str(), "%Y-%m-%d", &time)

void	BitcoinExchange::checkdate(std::string date)
{
	struct tm time;

	if (!strptime(date.c_str(), "%Y-%m-%d", &time))
		throw BadInput();
	// if (it->second < 0)
	// 	throw NotPositiveNumber();
	// if (it->second > 1000)
	// 	throw TooLargeNumber();
}

void	BitcoinExchange::checkvalue(double value)
{
	if (value < 0)
		throw NotPositiveNumber();
	if (value > 1000)
		throw TooLargeNumber();
}

double BitcoinExchange::getvalue(std::string date)
{
	std::map<std::string, double>::iterator rate;

	rate = this->_database.find(date);
	if (rate == this->_database.end())
	{
		rate = this->_database.lower_bound(date);
		if (rate == this->_database.end())
			return (--rate)->second;
		if (rate == this->_database.begin())
			return rate->second;
		return (--rate)->second;
	}
	return rate->second;
}

void BitcoinExchange::printresult(std::string filename)
{
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
		throw CannotOpenFile();

	std::string line;
	std::string date;
	while (std::getline(inputFile, line, '\n'))
	{
		if (line == "date | value")
			continue;
		try
		{
			BitcoinExchange::checkline(line);
			date = line.substr(0, 10);
			BitcoinExchange::checkdate(date);

		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << " => " << line << std::endl;
			continue;
		}
		double value;
		try
		{
			size_t i = line.find('|');
			if (i == std::string::npos)
				throw BadInput();
			i += 2;
			std::string stringValue = line.substr(i);
			value = std::atof(stringValue.c_str());
			BitcoinExchange::checkvalue(value);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			continue;
		}
		std::cout << date << " => " << value;
		std::cout << " = " << BitcoinExchange::getvalue(date) * value;
		std::cout << std::endl;
	}
}
