/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:11:02 by fli               #+#    #+#             */
/*   Updated: 2024/10/25 18:33:15 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	PhoneBook::nb_add = -1;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::Add(void)
{
	Contact	NewContact;

	NewContact.AddContact();
	this->nb_add++;
	this->contact[this->nb_add % 8] = NewContact;
}

static void	print_content(std::string str)
{
	if (str.length() >= 10)
		std::cout << str.substr(0, 8) << "." << "|";
	else
	{
		for (int i = 0; i < 10 - str.length(); i++)
			// space
		std::cout << str;
	}
}

void	PhoneBook::DisplayOneContact(int i)
{
	int	j = 5;

	while (j > 0)
	{
		print_content(this->contact[i].GetContactContent(j));
	}
}

void	PhoneBook::DisplayContacts(void)
{
	int	i = 0;

	std::cout << "     Index ";
	std::cout << "First Name ";
	std::cout << " Last Name ";
	std::cout << "  Nickname " << std::endl;
	while (i <= this->nb_add && i < 8)
	{
		std::cout << this->contact[i].GetContactContent
	}
}

void	PhoneBook::Search(void)
{

}
