/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:15:51 by fli               #+#    #+#             */
/*   Updated: 2024/11/12 21:58:41 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	// try
	// {
	// 	Bureaucrat	bureaucrat("bureaucrat", 151);
	// }
	// catch (std::exception & e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }

	// {
	// 	Bureaucrat	bureaucrat("bureaucrat", 19);
	// 	std::cout << bureaucrat << std::endl;
	// 	bureaucrat.incrementGrade();
	// 	std::cout << bureaucrat << std::endl;
	// 	bureaucrat.decrementGrade();
	// 	std::cout << bureaucrat << std::endl;
	// }

	// {
	// 	Bureaucrat	bureaucrat75("bureaucrat75", 75);
	// 	std::cout << bureaucrat75 << std::endl << std::endl;
	// 	Form	form;
	// 	std::cout << form << std::endl;
	// 	bureaucrat75.signForm(form);
	// }
	// std::cout << std::endl;
	// {
	// 	Bureaucrat	bureaucrat150("bureaucrat150", 150);
	// 	std::cout << bureaucrat150 << std::endl << std::endl;
	// 	Form	form20("form20", 20, 20);
	// 	std::cout << form20 << std::endl;
	// 	bureaucrat150.signForm(form20);
	// }

	{
		// try
		{
			Bureaucrat	mike("Mike", 10);

			ShrubberyCreationForm	form("forest");
			mike.executeForm(form);
			mike.signForm(form);

			mike.executeForm(form);
		}
		// catch(const std::exception& e)
		// {
		// 	std::cerr << e.what() << std::endl;
		// }
	}

	{
		// try
		{
			Bureaucrat	max("Max", 10);

			RobotomyRequestForm	form("non-robot");
			// max.signForm(form);

			max.executeForm(form);
		}
		// catch(const std::exception& e)
		// {
		// 	std::cerr << e.what() << std::endl;
		// }
	}

	{
		// try
		{
			Bureaucrat	mo("Mo", 10);

			PresidentialPardonForm form("me");
			// mo.signForm(form);

			mo.executeForm(form);
		}
		// catch(const std::exception& e)
		// {
		// 	std::cerr << e.what() << std::endl;
		// }
	}
}
