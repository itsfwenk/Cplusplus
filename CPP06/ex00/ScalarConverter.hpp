/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:37:46 by mli               #+#    #+#             */
/*   Updated: 2024/11/14 11:46:09 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>
# include <string>
# include <limits>
# include <iomanip>
# include <cstdlib>
# include <cmath>
# include <cctype>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &value);
		ScalarConverter & operator=(const ScalarConverter &value);


	public:
		virtual~ScalarConverter() = 0;
		static void	convert(std::string value);

		static bool	isChar(std::string value);
		static bool	isInt(std::string value);
		static bool	isFloat(std::string value);
		static bool	isDouble(std::string value);

		static void	printChar(std::string value);
		static void	printInt(std::string value);
		static void	printFloat(std::string value);
		static void	printDouble(std::string value);
		static void	printNanInf(std::string value);
};

#endif
