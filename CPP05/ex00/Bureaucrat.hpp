/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:16:03 by fli               #+#    #+#             */
/*   Updated: 2024/11/11 14:50:35 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

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
};

std::ostream &operator<<(std::ostream& stream, const Bureaucrat& bureaucrat);

#endif
