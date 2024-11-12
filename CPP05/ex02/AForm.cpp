/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:01:07 by mli               #+#    #+#             */
/*   Updated: 2024/11/12 22:07:13 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class AForm::GradeTooHighException : public std::exception
{
	public:
		const char *what() const throw()
		{
			return "error : grade too high";
		}
};

class AForm::GradeTooLowException : public std::exception
{
	public:
		const char *what() const throw()
		{
			return "error : grade too low";
		}
};

class AForm::NotSignedException : public std::exception
{
	public:
		const char *what() const throw()
		{
			return "error : form not signed";
		}
};

AForm::AForm()
	: _name("defaultAForm"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	// std::cout << "Default AForm constructor called" << std::endl;
}

AForm::~AForm()
{
	// std::cout << "Default AForm destructor called" << std::endl;
}

AForm::AForm(AForm const &other)
	: _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign),
		_gradeToExecute(other._gradeToExecute)
{
	// std::cout << "Copy AForm constructor called" << std::endl;
	this->target = other.target;
}

AForm const &AForm::operator=(AForm const &other)
{
	// std::cout << "AForm copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_signed = other._signed;
		this->target = other.target;
	}
	return *this;
}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute, std::string target)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	// std::cout << "AForm constructor called" << std::endl;
	this->target = target;
}

std::string AForm::getName() const
{
	return this->_name;
}

int AForm::getGradeToSign() const
{
	return this->_gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

bool AForm::isSigned() const
{
	return this->_signed;
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		this->_signed = true;
		std::cout << bureaucrat.getName() << " signed " << this->_name << std::endl;
	}
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream& stream, const AForm& form)
{
	stream << "Form: " << form.getName() << std::endl;
	stream << "Grade to sign: " << form.getGradeToSign() << std::endl;
	stream << "Grade to execute: " << form.getGradeToExecute() << std::endl;
	stream << "Signed: " << form.isSigned() << std::endl;
	return stream;
}

bool	AForm::checkRequirements(const Bureaucrat & executor) const
{
	if (executor.getGrade() > this->_gradeToExecute)
		throw GradeTooLowException();
	else if (this->isSigned() == false)
		throw NotSignedException();
	return (true);
}

std::string AForm::getTarget() const
{
	return this->target;
}

void AForm::setSigned(bool isSigned)
{
	this->_signed = isSigned;
}
