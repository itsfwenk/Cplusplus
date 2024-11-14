/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:15:51 by fli               #+#    #+#             */
/*   Updated: 2024/11/14 19:39:48 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
		const char	*what() const throw()
		{
			return "error : grade too low (min grade : 1)";
		}
};

Bureaucrat::Bureaucrat() : Name("defaultBureaucrat"), Grade(150)
{
	// std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << "Bureaucrat default destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : Name(other.Name), Grade(other.Grade)
{
	// std::cout << "Bureaucrat copy conSstructor called" << std::endl;
}

Bureaucrat const &Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this != &other)
		this->Grade = other.Grade;
	return (*this);
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : Name(name)
{
		if (grade < 1)
			throw  Bureaucrat::GradeTooLowException();
		else if (grade > 150)
			throw  Bureaucrat::GradeTooHighException();
		this->Grade = grade;
}

std::string Bureaucrat::getName() const
{
	return (this->Name);
}

int Bureaucrat::getGrade() const
{
	return (this->Grade);
}

void	Bureaucrat::incrementGrade()
{
		if (this->Grade - 1 < 1)
			throw Bureaucrat::GradeTooLowException();
		this->Grade--;
		std::cout << this->Name << " has been promoted to grade " << this->Grade << std::endl;
}

void	Bureaucrat::decrementGrade()
{
	if (this->Grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->Grade++;
	std::cout << this->Name << " has been demoted to grade " << this->Grade << std::endl;
}

std::ostream &operator<<(std::ostream& stream, const Bureaucrat& bureaucrat)
{
	stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (stream);
}

void Bureaucrat::signForm(AForm &form) const
{
	// if (this->Grade <= form.getGradeToSign())
	// {
	// 	form.beSigned(*this);
	// }
	// else
	// {
	// 	std::cout << this->Name << " couldn't sign " << form.getName();
	// 	std::cout << " because grade equal or higher than " << form.getGradeToSign();
	// 	std::cout << " needed." << std::endl;
	// }
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << this->Name << " couldn't sign form " << form.getName() << " because the bureaucrat grade is too low!" << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->Name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cout << this->Name << " couldn't execute form " << form.getName() << " because " << e.what() << std::endl;
	}
}
