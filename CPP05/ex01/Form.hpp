/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:48:40 by mli               #+#    #+#             */
/*   Updated: 2024/11/12 16:42:24 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool 							_signed;
		const int					_gradeToSign;
		const int					_gradeToExecute;

	public:
		Form();
		~Form();
		Form(Form const &other);
		Form const &operator=(Form const &other);

		Form(const std::string name, int gradeToSign, int gradeToExecute);

		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool isSigned() const;

		void beSigned(Bureaucrat const &bureaucrat);

		class GradeTooHighException;
		class GradeTooLowException;
};

std::ostream &operator<<(std::ostream& stream, const Form& form);

#endif
