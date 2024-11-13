/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:16:52 by mli               #+#    #+#             */
/*   Updated: 2024/11/13 14:53:16 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	std::string	forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm* (*formsFunc[])(std::string target) =
	{
		&PresidentialPardonForm::newForm,
		&RobotomyRequestForm::newForm,
		&ShrubberyCreationForm::newForm
	};
	for (int i = 0; i < 3; i++)
	{
		if (formName == forms[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (formsFunc[i])(target);
		}
	}
	std::cout << "Intern cannot create " << formName << std::endl;
	throw Intern::FormNotFoundException();
}
