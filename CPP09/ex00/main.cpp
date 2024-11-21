/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:56:40 by fli               #+#    #+#             */
/*   Updated: 2024/11/21 17:56:04 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Invalid number of parameters" << std::endl;
		return (EXIT_FAILURE);
	}
	std::ifstream	inputFile(av[1]);
	if (!inputFile.is_open())
	{
		std::cerr << "Failed to open the file." << std::endl;
		return (EXIT_FAILURE);
	}
	std::string line;
	while (std::getline(inputFile, line))
	{
		if (!checkline(line))
		{
			std::cerr << "Invalid file content" << std::endl;
			return (EXIT_FAILURE);
		}
	}
	inputFile.close();

	std::map<>
}
