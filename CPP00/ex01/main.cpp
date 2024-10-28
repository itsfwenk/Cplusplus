/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:24:59 by fli               #+#    #+#             */
/*   Updated: 2024/10/28 13:11:04 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
	std::string	input;
	PhoneBook	phonebook;

	std::cout << "This is your awesome phonebook." << std::endl;
	std::cout << "To add a new contact, enter ADD." << std::endl;
	std::cout << "To search for a contact, enter SEARCH." << std::endl;
	std::cout << "To exit your phonebook, enter EXIT." << std::endl;
	while (1)
	{
		std::cout << "> ";
		std::cin >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (input == "ADD")
			phonebook.Add();
		else if (input == "SEARCH")
			phonebook.Search();
		else if (input == "EXIT")
			exit(EXIT_SUCCESS);
	}
}
