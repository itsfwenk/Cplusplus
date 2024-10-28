/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:44:13 by fli               #+#    #+#             */
/*   Updated: 2024/10/28 13:31:13 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

static void	print_request(int i)
{
	if (i == 5)
		std::cout << "Enter first name : ";
	else if (i == 4)
		std::cout << "Enter last name : ";
	else if (i == 3)
		std::cout << "Enter nickname : ";
	else if (i == 2)
		std::cout << "Enter phone number : ";
	else if (i == 1)
		std::cout << "Enter darkest secret : ";
}

static bool	only_digits(std::string number)
{
	if (number.empty())
		return (false);
	for (std::string::iterator it = number.begin(); it != number.end(); ++it)
	{
		if (isdigit(*it) == 0)
			return (false);
	}
	return (true);
}

static bool	check_input(int i, std::string user_input)
{
	if (user_input.empty())
	{
		std::cout << "Cannot have empty fields." << std::endl;
		return (false);
	}
	if (i == 2)
	{
		if (only_digits(user_input) == false)
		{
			std::cout << "Phone number should contain digits only. Please enter a valid number." << std::endl;
			return (false);
		}
	}
	return (true);
}

void	Contact::StoreInfo(int i, std::string input)
{
	if (i == 5)
		this->first_name = input;
	else if (i == 4)
		this->last_name = input;
	else if (i == 3)
		this->nickname = input;
	else if (i == 2)
		this->phone_number = input;
	else if (i == 1)
		this->darkest_secret = input;
}

void	Contact::AddContact(void)
{
	int	i = 5;
	std::string	user_input = "\n";

	while (i > 0)
	{
		print_request(i);
		std::getline(std::cin, user_input);
		if (std::cin.eof())
		{
			std::cin.clear();
			user_input.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return ;
		}
		if (check_input(i, user_input) == false)
			continue;
		this->StoreInfo(i, user_input);
		i--;
	}
}

std::string	Contact::GetContactContent(int i)
{
	if (i == 5)
		return (this->first_name);
	else if (i == 4)
		return (this->last_name);
	else if (i == 3)
		return (this->nickname);
	else if (i == 2)
		return (this->phone_number);
	return (this->darkest_secret);
}
