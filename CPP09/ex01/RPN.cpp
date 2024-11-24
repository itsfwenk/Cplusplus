/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:50:01 by mli               #+#    #+#             */
/*   Updated: 2024/11/24 16:05:03 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &other) : _stack(other._stack)
{
}

RPN& RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		this->_stack = other._stack;
	}
	return *this;
}

bool	RPN::isoperator(char c)
{
	char	ops[] = { '+', '-', '/', '*' };
	int		max_ops = 4;

	for (int i = 0; i < max_ops; i++)
	{
		if (ops[i] == c)
			return (true);
	}
	return (false);
}

void RPN::checkinput(std::string input)
{
	if (input.empty())
		throw InvalidRPN();

	bool between = false;
	size_t i = 0;
	while (i < input.length() && input[i] == ' ')
		i++;
	if (!isdigit(input[i]))
		throw InvalidRPN();
	for (size_t j = i; j < input.length(); j++)
	{
		if (!between && !RPN::isoperator(input[j]) && !isdigit(input[j]))
			throw InvalidRPN();
		else if (between && input[j] != ' ')
			throw InvalidRPN();
		between = !between;
	}
}

void RPN::checkvalue(double value)
{
	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		throw OutOfRange();
}

void RPN::add()
{
	long long a = this->_stack.top();
	this->_stack.pop();
	long long b = this->_stack.top();
	this->_stack.pop();
	RPN::checkvalue(a + b);
	this->_stack.push(a + b);
}

void RPN::subtract()
{
	long long a = this->_stack.top();
	this->_stack.pop();
	long long b = this->_stack.top();
	this->_stack.pop();
	RPN::checkvalue(a - b);
	this->_stack.push(b - a);
}

void RPN::multiply()
{
	long long a = this->_stack.top();
	this->_stack.pop();
	long long b = this->_stack.top();
	this->_stack.pop();
	RPN::checkvalue(a * b);
	this->_stack.push(a * b);
}

void RPN::divide()
{
	long long a = this->_stack.top();
	this->_stack.pop();
	long long b = this->_stack.top();
	this->_stack.pop();
	RPN::checkvalue(b / a);
	this->_stack.push(b / a);
}

void RPN::calculate(std::string input)
{
	RPN::checkinput(input);
	std::string::iterator it = input.begin();
	while (it != input.end() && *it == ' ')
		it++;

	long long value;
	char c;
	while (it != input.end())
	{
		c = *it;
		if (isdigit(c))
		{
			value = std::atoll(&c);
			this->_stack.push(value);
		}
		else if (RPN::isoperator(c))
		{
			if (c == '+')
				RPN::add();
			else if (c == '-')
				RPN::subtract();
			else if (c == '*')
				RPN::multiply();
			else if (c == '/')
				RPN::divide();
		}
		it++;
	}
}

int RPN::getTop()
{
	return (this->_stack.top());
}
