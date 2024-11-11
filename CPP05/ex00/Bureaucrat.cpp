/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:15:51 by fli               #+#    #+#             */
/*   Updated: 2024/11/11 15:04:07 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : Name("defaultBureaucrat"), Grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat default destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : Name(other.Name), Grade(other.Grade)
{
	std::cout << "Bureaucrat copy conSstructor called" << std::endl;
}

Bureaucrat const &Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this != &other)
		this->Grade = other.Grade;
	return (*this);
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
{
	try
	{
		if (grade < 1)
			throw  Bureaucrat::GradeTooLowException;
		if (grade > 150)
			throw  Bureaucrat::GradeTooHighException;
	}
}

std::string const &Bureaucrat::getName()
{
	return (this->Name);
}

int Bureaucrat::getGrade()
{
	return (this->Grade);
}

void	Bureaucrat::incrementGrade()
{
	try
	{
		this->Grade++;
		if (this->Grade > 150)
			throw Bureaucrat::GradeTooHighException;
	}
	catch (Bureaucrat::GradeTooHighException)
	{

	}
}

void	Bureaucrat::decrementGrade()
{
	try
	{
		this->Grade--;
		if (this->Grade < 1)
			throw Bureaucrat::GradeTooLowException;
	}
	catch (Bureaucrat::GradeTooLowException)
	{

	}
}

class Bureaucrat::GradeTooHighException : public std::exception
{
	public:
		const char	*what() const throw()
		{
			return "error : grade too high (max grade : 150)";
		}
};

class Bureaucrat::GradeTooLowException : public std::exception
{
	public:
		const char	*what() const noexcept override
		{
			return "error : grade too low (min grade : 1)";
		}
};
