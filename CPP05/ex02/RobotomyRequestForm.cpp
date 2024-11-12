/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:40:06 by mli               #+#    #+#             */
/*   Updated: 2024/11/12 22:10:26 by mli              ###   ########.fr       */
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

void	RobotomyRequestForm::execute(const Bureaucrat & executor) const
{
	this->checkRequirements(executor);

	std::cout << "*makes some drilling noise*" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->getTarget() << " has not been robotomized." << std::endl;
}
