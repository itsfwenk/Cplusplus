/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:11:02 by fli               #+#    #+#             */
/*   Updated: 2024/10/28 14:02:26 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	PhoneBook::nb_add = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::Add(void)
{
	int		index;
	Contact	NewContact;

	NewContact.AddContact();
	this->nb_add++;
	index = this->nb_add - 1;
	this->contact[index % 8] = NewContact;
}

static void	print_content(std::string str)
{
	if (str.length() >= 10)
		std::cout << str.substr(0, 9) << "." << "|";
	else
	{
		for (int i = 0; i < 10 - (int)str.length(); i++)
			std::cout << " ";
		std::cout << str << "|";
	}
}

void	PhoneBook::DisplayOneContact(int i)
{
	int	j = 5;

	while (j > 2)
	{
		print_content(this->contact[i].GetContactContent(j));
		j--;
	}
}

void	PhoneBook::DisplayContacts(void)
{
	int	i = 0;

	std::cout << "|    Index|";
	std::cout << "First Name|";
	std::cout << " Last Name|";
	std::cout << "  Nickname|" << std::endl;
	while (i < this->nb_add && i < 8)
	{
		std::cout << "|        " << i + 1 << "|";
		this->DisplayOneContact(i);
		i++;
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void	PhoneBook::Search(void)
{
	int			index;
	std::string	input;

	this->DisplayContacts();
	std::cout << "INDEX = ";
	std::cin >> input;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::stringstream ss(input);
	ss >> index;
	while (index <= 0 || index > this->nb_add || index > 8)
	{
		std::cout << "INDEX is out of range." << std::endl;
		std::cout << "Please enter a number between 1 and 8 : ";
		std::cin >> input;
		std::stringstream ss(input);
		ss >> index;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	index = index - 1;
	std::cout << this->contact[index].GetContactContent(5) << std::endl;
	std::cout << this->contact[index].GetContactContent(4) << std::endl;
	std::cout << this->contact[index].GetContactContent(3) << std::endl;
	std::cout << this->contact[index].GetContactContent(2) << std::endl;
	std::cout << this->contact[index].GetContactContent(1) << std::endl;
}
