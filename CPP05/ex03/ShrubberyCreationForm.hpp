/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:48:40 by mli               #+#    #+#             */
/*   Updated: 2024/11/16 13:49:08 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Bureaucrat.hpp"
# include <fstream>

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	private:

	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &other);
		ShrubberyCreationForm const &operator=(ShrubberyCreationForm const &other);

		static AForm *newForm(std::string target);

		ShrubberyCreationForm(std::string target);
		void	execute(const Bureaucrat & executor) const;
};

#endif
