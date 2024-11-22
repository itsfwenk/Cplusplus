/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:04:49 by fli               #+#    #+#             */
/*   Updated: 2024/11/22 19:13:00 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <fstream>
# include <string>
# include <stdlib.h>
# include <cstdlib>
# include <limits>
# include <exception>
# include <cmath>
# include <iomanip>
# include <cctype>

class BitcoinExchange
{
	private:
	std::map<std::string, double> _database;

	public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange& operator=(const BitcoinExchange &other);

	BitcoinExchange(std::string filename);

	void checkline(std::string line);
	// static void	checkinput(std::map<std::string, double>::const_iterator it);
	void checkdate(std::string date);
	void checkvalue(double value);
	void printresult(std::string filename);

	class CannotOpenFile;
	class BadInput;
	class NotPositiveNumber;
	class TooLargeNumber;
};

#endif
