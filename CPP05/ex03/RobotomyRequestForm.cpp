/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:40:06 by mli               #+#    #+#             */
/*   Updated: 2024/11/14 15:44:24 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Presidential Pardon Form", 72, 45, "defaultTarget")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Presidential Pardon Form", 72, 45, target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
	: AForm(other)
{
}

RobotomyRequestForm const &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	if (this != &other)
	{
		this->setSigned(other.isSigned());
		this->target = other.target;
	}
	return *this;
}

AForm *RobotomyRequestForm::newForm(std::string target)
{
	RobotomyRequestForm *form = new RobotomyRequestForm(target);
	return form;
}

void	RobotomyRequestForm::execute(const Bureaucrat & executor) const
{
	this->checkRequirements(executor);

	std::srand(std::time(0));

	std::cout << "*makes some drilling noise*" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->getTarget() << " has not been robotomized." << std::endl;
}
