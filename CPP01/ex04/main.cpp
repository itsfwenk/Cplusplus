/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:02:10 by fli               #+#    #+#             */
/*   Updated: 2024/11/04 15:41:08 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int main(int ac, char **av)
{
	if (ac != 4 || av[2][0] == '\0')
	{
		std::cout << "Invalid parameters." << std::endl;
		return(0);
	}
	std::ifstream	inputFile(av[1]);
	if (!inputFile.is_open())
	{
		std::cerr << "Failed to open the file." << std::endl;
		return (1);
	}
	std::fstream	replaceFile;
	replaceFile.open((std::string)av[1] + (const std::string)".replace", std::fstream::out);
	if (!replaceFile.is_open())
	{
		inputFile.close();
		std::cerr << "Failed to create .replace file" << std::endl;
		return (1);
	}
	char		c;
	std::string	fileContent;
	while (inputFile.get(c))
	{
		fileContent += c;
	}
	inputFile.close();
	int	i = 0;
	std::string	part1;
	std::string	part2 = fileContent;
	while (fileContent[i])
	{
		i = fileContent.find(av[2]);
		if (i == std::string::npos)
			break;
		part1 = fileContent.substr(0, i);
		part2 = fileContent.substr((i + ((std::string)av[2]).length()));
		replaceFile << part1 << av[3];
		fileContent = part2;
	}
	replaceFile << part2;
	replaceFile.close();
}
