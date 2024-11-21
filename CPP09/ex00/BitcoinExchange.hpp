/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:04:49 by fli               #+#    #+#             */
/*   Updated: 2024/11/21 18:25:33 by fli              ###   ########.fr       */
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

class BitcoinExchange
{
	private:
	BitcoinExchange();
	std::map<std::string, double, std::greater<std::string>> _database;

	public:
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange& operator=(const BitcoinExchange &other);

	BitcoinExchange(std::string filename);

	bool	checkline(std::string line);

	class InvalidFile;
};

#endif
