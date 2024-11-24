/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:56:40 by fli               #+#    #+#             */
/*   Updated: 2024/11/24 12:07:10 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (EXIT_FAILURE);
	}
	std::ifstream	inputFile(av[1]);
	if (!inputFile.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (EXIT_FAILURE);
	}
	BitcoinExchange	 database;
	// std::string line;
	// while (std::getline(inputFile, line))
	// {
	// 	if (line == "date | value")
	// 		continue;
	// 	database.printresult(line);
	// }
	database.printresult(av[1]);
	inputFile.close();
}
