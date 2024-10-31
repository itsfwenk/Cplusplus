/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:02:10 by fli               #+#    #+#             */
/*   Updated: 2024/10/31 11:01:07 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Invalid number of parameters. Please enter a filename and two strings";
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
	std::string	line;
	std::string	fileContent;
	while (std::getline(inputFile, line))
	{
		fileContent.append(line);
		fileContent.append("\n");
	}
	int	i = 0;
	std::string	part1;
	std::string	part2;
	while (fileContent[i])
	{
		i = fileContent.find(av[2]);
		if (i == std::string::npos)
			break;
		part1 = fileContent.substr(0, i);
		part2 = fileContent.substr((i + ((std::string)av[2]).length()));
		fileContent = part1 + av[3] + part2;
	}
	replaceFile << fileContent;
}
