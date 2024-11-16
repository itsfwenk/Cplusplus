/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:40:25 by mli               #+#    #+#             */
/*   Updated: 2024/11/16 13:49:03 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137, "defaultTarget")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137, target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
	: AForm(other)
{
}

ShrubberyCreationForm const &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this != &other)
	{
		this->setSigned(other.isSigned());
		this->target = other.target;
	}
	return *this;
}

void	ShrubberyCreationForm::execute(const Bureaucrat & executor) const
{
	this->checkRequirements(executor);

	std::string	fileName = this->getTarget() + "_shrubbery";
	std::fstream	shrubberyFile;
	shrubberyFile.open(fileName.c_str(), std::fstream::out);
	if (!shrubberyFile.is_open())
		throw std::runtime_error("Failed to create shrubbery file.");

	shrubberyFile << "                                  # #### ####" << std::endl;
	shrubberyFile << "                                ### \\/#|### |/####" << std::endl;
	shrubberyFile << "                               ##\\/#/ \\||/##/_/##/_#" << std::endl;
	shrubberyFile << "                             ###  \\/###|/ \\/ # ###" << std::endl;
	shrubberyFile << "                           ##_\\_#\\_\\## | #/###_/_####" << std::endl;
	shrubberyFile << "                          ## #### # \\ #| /  #### ##/##" << std::endl;
	shrubberyFile << "                           __#_--###`  |{,###---###-~" << std::endl;
	shrubberyFile << "                                     \\ }{" << std::endl;
	shrubberyFile << "                                      }}{" << std::endl;
	shrubberyFile << "                                      }}{" << std::endl;
	shrubberyFile << "                                      {{}" << std::endl;
	shrubberyFile << "                                , -=-~{ .-^- _" << std::endl;
	shrubberyFile.close();
}

AForm *ShrubberyCreationForm::newForm(std::string target)
{
	ShrubberyCreationForm *form = new ShrubberyCreationForm(target);
	return form;
}
