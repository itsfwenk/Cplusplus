/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:16:03 by fli               #+#    #+#             */
/*   Updated: 2024/11/12 16:38:57 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	Name;
		int					Grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &other);
		Bureaucrat const &operator=(Bureaucrat const &other);

		Bureaucrat(const std::string name, int grade);
		std::string getName() const;
		int getGrade() const;
		void	incrementGrade();
		void	decrementGrade();

		class GradeTooHighException;
		class GradeTooLowException;

		void	signForm(Form form);
};

std::ostream &operator<<(std::ostream& stream, const Bureaucrat& bureaucrat);

#endif
