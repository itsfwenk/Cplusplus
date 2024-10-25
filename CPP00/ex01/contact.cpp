/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:44:13 by fli               #+#    #+#             */
/*   Updated: 2024/10/25 18:16:05 by fli              ###   ########.fr       */
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
		i--;
	}
}

static void	print_content(std::string str)
{
	if (str.length() >= 10)
		std::cout << str.substr(0, 8) << "." << std::endl;
	else
		std::cout << str << std::endl;
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
	else if (i == 1)
		return (this->darkest_secret);
}
