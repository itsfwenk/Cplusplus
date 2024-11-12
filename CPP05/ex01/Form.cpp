/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:01:07 by mli               #+#    #+#             */
/*   Updated: 2024/11/12 16:46:06 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

class Form::GradeTooHighException : public std::exception
{
	public:
		const char *what() const throw()
		{
			return "error : grade too high";
		}
};

class Form::GradeTooLowException : public std::exception
{
	public:
		const char *what() const throw()
		{
			return "error : grade too low";
		}
};

Form::Form()
	: _name("defaultForm"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	// std::cout << "Default Form constructor called" << std::endl;
}

Form::~Form()
{
	// std::cout << "Default Form destructor called" << std::endl;
}

Form::Form(Form const &other)
	: _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign),
		_gradeToExecute(other._gradeToExecute)
{
	// std::cout << "Copy Form constructor called" << std::endl;
}

Form const &Form::operator=(Form const &other)
{
	// std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_signed = other._signed;
	}
	return *this;
}

Form::Form(const std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	// std::cout << "Form constructor called" << std::endl;
}

std::string Form::getName() const
{
	return this->_name;
}

int Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

bool Form::isSigned() const
{
	return this->_signed;
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		this->_signed = true;
		std::cout << bureaucrat.getName() << " signed " << this->_name << std::endl;
	}
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream& stream, const Form& form)
{
	stream << "Form: " << form.getName() << std::endl;
	stream << "Grade to sign: " << form.getGradeToSign() << std::endl;
	stream << "Grade to execute: " << form.getGradeToExecute() << std::endl;
	stream << "Signed: " << form.isSigned() << std::endl;
	return stream;
}

