/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:50:00 by mli               #+#    #+#             */
/*   Updated: 2024/11/24 16:04:54 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>
# include <exception>
# include <limits>
# include <cstdlib>

class RPN
{
	private:
	std::stack<int> _stack;

	public:
	RPN();
	~RPN();
	RPN(const RPN &other);
	RPN& operator=(const RPN &other);

	bool isoperator(char c);

	void checkinput(std::string input);

	void checkvalue(double value);

	void add();
	void subtract();
	void multiply();
	void divide();
	void calculate(std::string input);

	int getTop();

	class InvalidRPN : public std::exception
	{
		const char *what() const throw()
		{
			return "error : invalid RPN";
		}
	};

	class OutOfRange : public std::exception
	{
		const char *what() const throw()
		{
			return "error : out of range";
		}
	};
};

#endif
