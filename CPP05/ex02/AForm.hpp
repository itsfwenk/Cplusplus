/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:48:40 by mli               #+#    #+#             */
/*   Updated: 2024/11/12 22:06:45 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool 							_signed;
		const int					_gradeToSign;
		const int					_gradeToExecute;

	protected:
		std::string 			target;

		public:
		AForm();
		virtual ~AForm();
		AForm(AForm const &other);
		AForm const &operator=(AForm const &other);

		AForm(const std::string name, int gradeToSign, int gradeToExecute, std::string target);

		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool isSigned() const;

		void beSigned(Bureaucrat const &bureaucrat);

		void setSigned(bool isSigned);

		class GradeTooHighException;
		class GradeTooLowException;
		class NotSignedException;

		virtual void	execute(const Bureaucrat & executor) const = 0;
		bool	checkRequirements(const Bureaucrat & executor) const;
		std::string getTarget() const;
};

std::ostream &operator<<(std::ostream& stream, const AForm& form);

#endif
