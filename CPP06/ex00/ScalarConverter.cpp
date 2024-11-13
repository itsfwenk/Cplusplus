/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:48:26 by mli               #+#    #+#             */
/*   Updated: 2024/11/14 00:09:02 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &value)
{
	(void)value;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter &value)
{
	(void)value;
	return *this;
}

bool	ScalarConverter::isChar(std::string value)
{
	if (value.empty() || value.length() > 1)
		return (false);
	// if (!isprint(value[0]))
	// 	return (false);
	return (true);
}

bool	ScalarConverter::isInt(std::string value)
{
	int	e = 0;
	int	plus = 0;
	int	minus = 0;

	if (value.empty())
		return (false);
	if (value.length() == 2 && value[0] == '-')
		return (true);
	for (size_t i = 0; i < value.length(); i++)
	{
		if (i == 0 && value[i] == '-')
			continue;
		if (value[i] == 'e')
		{
			e++;
			continue;
		}
		if (value[i] == '+')
		{
			plus++;
			continue;
		}
		if (value[i] == '-')
		{
			minus++;
			continue;
		}
		if (!isdigit(value[i]))
			return (false);
	}
	if (std::atoll(value.c_str()) > std::numeric_limits<int>::max()
		|| std::atoll(value.c_str()) < std::numeric_limits<int>::min())
		return (false);
	if (e > 1 && plus > 1)
		return (false);
	return (true);
}

bool	ScalarConverter::isFloat(std::string value)
{
	int	dot = 0;

	if (value.empty())
		return (false);
	for (size_t i = 0; i < value.length(); i++)
	{
		if (i == 0 && value[i] == '-')
			continue;
		if (i == value.length() - 1 && value[i] == 'f')
			continue;
		if (value[i] == '.')
			dot++;
		if (!isdigit(value[i]) && value[i] != '.')
			return (false);
	}
	if (dot > 1)
		return (false);
	if (value.rbegin()[0] == 'f')
		return (true);
	return (false);

	// if (value.rbegin()[0] == 'f' && value.find(".") != std::string::npos)
	// 	return (true);
	// return (false);
}

bool	ScalarConverter::isDouble(std::string value)
{
	int	dot = 0;

	if (value.empty())
		return (false);
	for (size_t i = 0; i < value.length(); i++)
	{
		if (i == 0 && value[i] == '-')
			continue;
		if (value[i] == '.')
			dot++;
		if (!isdigit(value[i]) && value[i] != '.')
			return (false);
	}
	if (dot > 1)
		return (false);
	return (true);

	// if (value.find(".") == std::string::npos)
	// 	return (false);
	// return (true);
}

void	ScalarConverter::printChar(std::string value)
{
	int	val;

	val = static_cast<int>(value.c_str()[0]);
	std::cout << "char: ";
	if (ScalarConverter::isChar(value) && isprint(val))
		std::cout << '\'' << char(val) << '\'';
	else if (ScalarConverter::isChar(value) && !isprint(val))
		std::cout << "non displayable";
	else
		std::cout << "impossible";
	std::cout << std::endl;
}

void	ScalarConverter::printInt(std::string value)
{
	double	val;

	std::cout << "int: ";

	if (ScalarConverter::isChar(value) && isdigit(value[0]))
		std::cout << std::atof(value.c_str());
	else if (ScalarConverter::isChar(value) && !isdigit(value[0]))
		std::cout << static_cast<int>(value[0]);
	else if (ScalarConverter::isInt(value))
	{
		val = static_cast<int>(std::atof(value.c_str()));
		if (value.length() == 2 && value[0] == '-')
			val = -1 * static_cast<int>(value[1]);
		if (val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min())
			std::cout << "out of range";
		else
			std::cout << val;
	}
	else if (ScalarConverter::isFloat(value) || ScalarConverter::isDouble(value))
	{
		val = static_cast<long long>(std::atof(value.c_str()));
		if (val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min())
			std::cout << "out of range";
		else
			std::cout << val;
	}
	else
		std::cout << "impossible";
	std::cout << std::endl;
}

void ScalarConverter::printFloat(std::string value)
{
	double	val;

	std::cout << "float: ";
	if (ScalarConverter::isChar(value) && isdigit(value[0]))
	{
		std::cout << static_cast<float>(std::atof(value.c_str())) << ".0f" << std::endl;
		return ;
	}
	else if (ScalarConverter::isChar(value) && !isdigit(value[0]))
	{
		std::cout << static_cast<int>(value[0]) << ".0f" << std::endl;
		return ;
	}
	else if (ScalarConverter::isInt(value))
	{
		val = static_cast<double>(std::atof(value.c_str()));
		if (value.length() == 2 && value[0] == '-')
			val = -1 * static_cast<int>(value[1]);
		std::cout << val << ".0f" << std::endl;
		return ;
	}
	else if (ScalarConverter::isFloat(value) || ScalarConverter::isDouble(value))
		std::cout << static_cast<float>(std::atof(value.c_str()));
	if (std::floor(static_cast<float>(std::atof(value.c_str()))) == static_cast<float>(std::atof(value.c_str()))
		&& !std::isfinite(static_cast<float>(std::atof(value.c_str())))
		&& value.find("e") == std::string::npos)
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble(std::string value)
{
	double	val = static_cast<double>(std::atof(value.c_str()));

	std::cout << "double: ";
	if (ScalarConverter::isChar(value) && isdigit(value[0]))
	{
		std::cout << val << ".0" << std::endl;
		return ;
	}
	else if (ScalarConverter::isChar(value) && !isdigit(value[0]))
	{
		std::cout << static_cast<int>(value[0]) << ".0" << std::endl;
		return ;
	}
	else if (ScalarConverter::isInt(value))
	{
		if (value.length() == 2 && value[0] == '-')
			val = -1 * static_cast<int>(value[1]);
		std::cout << val << ".0f" << std::endl;
		return ;
	}
	else if (ScalarConverter::isFloat(value) || ScalarConverter::isDouble(value))
		std::cout << val;
	if (std::floor(val) == val
		&& !std::isfinite(val)
		&& value.find("e") == std::string::npos)
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::printNanInf(std::string value)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (value == "-nanf" || value == "-nan")
	{
		std::cout << "float: -nanf" << std::endl;
		std::cout << "double: -nan" << std::endl;
	}
	else if (value == "inff" || value == "inf")
	{
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	}
	else if (value == "-inff" || value == "-inf")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
}

void ScalarConverter::convert(std::string value)
{
	std::cout << ScalarConverter::isChar(value) << std::endl;
	std::cout << ScalarConverter::isInt(value) << std::endl;
	std::cout << ScalarConverter::isFloat(value) << std::endl;
	std::cout << ScalarConverter::isDouble(value) << std::endl;
	if (!ScalarConverter::isChar(value) && !ScalarConverter::isInt(value) && !ScalarConverter::isFloat(value) && !ScalarConverter::isDouble(value))
		ScalarConverter::printNanInf(value);
	else
	{
		ScalarConverter::printChar(value);
		ScalarConverter::printInt(value);
		ScalarConverter::printFloat(value);
		ScalarConverter::printDouble(value);
	}
}
