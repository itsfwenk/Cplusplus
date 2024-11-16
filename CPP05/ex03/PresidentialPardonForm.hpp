/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:48:40 by mli               #+#    #+#             */
/*   Updated: 2024/11/16 13:48:23 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:

	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &other);
		PresidentialPardonForm const &operator=(PresidentialPardonForm const &other);

		static AForm *newForm(std::string target);

		PresidentialPardonForm(std::string target);
		void	execute(const Bureaucrat & executor) const;
};

#endif
