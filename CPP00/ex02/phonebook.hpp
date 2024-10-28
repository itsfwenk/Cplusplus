/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:27:33 by fli               #+#    #+#             */
/*   Updated: 2024/10/28 13:31:41 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <string>
# include <iostream>
# include <limits>
# include <stdexcept>
# include <sstream>
# include <cstdlib>
# include <cstdio>

class	Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;

	public:
	Contact(void);
	~Contact(void);
	void		AddContact(void);
	std::string	GetContactContent(int i);
	void		StoreInfo(int i, std::string input);
};

class	PhoneBook
{
	private:
		int		nb_add;
		Contact	contact[8];

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	Add(void);
		void	Search(void);
		void	DisplayContacts(void);
		void	DisplayOneContact(int i);
};

#endif
