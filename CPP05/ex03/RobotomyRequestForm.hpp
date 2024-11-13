/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:48:40 by mli               #+#    #+#             */
/*   Updated: 2024/11/13 13:52:00 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Bureaucrat.hpp"
# include <cstdlib>

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:

	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &other);
		RobotomyRequestForm const &operator=(RobotomyRequestForm const &other);

		static AForm *newForm(std::string target);

		RobotomyRequestForm(const std::string name, int gradeToSign, int gradeToExecute);
		RobotomyRequestForm(std::string target);
		void	execute(const Bureaucrat & executor) const;
};

#endif
