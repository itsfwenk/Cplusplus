/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:31:21 by fli               #+#    #+#             */
/*   Updated: 2024/11/20 17:25:38 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

class Span::StorageFull : public std::exception
{
	public :
		const char *what() const throw()
		{
			return "error : max storage reached";
		}
};

class Span::NoSpanFound : public std::exception
{
	public :
		const char *what() const throw()
		{
			return "error : no span can be found";
		}
};

class Span::OutOfRange : public std::exception
{
	public :
		const char *what() const throw()
		{
			return "error : out of range";
		}
};

Span::Span()
{
}

Span::~Span()
{
}

Span::Span(const Span &other) : _maxInt(other._maxInt), _storage(other._storage)
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_maxInt = other._maxInt;
		this->_storage = other._storage;
	}
	return *this;
}

Span::Span(unsigned int maxInt) : _maxInt(maxInt)
{
}

void Span::addNumber(int toAdd)
{
	if (this->_storage.size() + 1 > (size_t)this->_maxInt)
		throw Span::StorageFull();
	this->_storage.push_back(toAdd);
}

void Span::addNumber(std::vector<int> toAdd)
{
	if (this->_storage.size() + toAdd.size() > (size_t)this->_maxInt)
		throw Span::StorageFull();
	this->_storage.insert(this->_storage.end(), toAdd.begin(), toAdd.end());
}

int Span::shortestSpan()
{
	if (this->_storage.size() <= 1)
		throw NoSpanFound();

	std::vector<int> sortedVec = this->_storage;
	std::sort(sortedVec.begin(), sortedVec.end());
	int minSpan = abs(*sortedVec.begin() - *(sortedVec.begin() + 1));

	for (std::vector<int>::iterator it = sortedVec.begin() + 1; it != sortedVec.end(); it++)
	{
		int tmp = abs(*it - *(it + 1));
		if (tmp < minSpan)
			minSpan = tmp;
	}
	return (minSpan);
}

int Span::longestSpan()
{
	if (this->_storage.size() <= 1)
		throw NoSpanFound();

	std::vector<int>::iterator max = std::max_element(this->_storage.begin(), this->_storage.end());
	std::vector<int>::iterator min = std::min_element(this->_storage.begin(), this->_storage.end());

	return (*max - *min);
}

const int& Span::operator[](size_t idx) const
{
	if (idx <= this->_storage.size())
		return this->_storage[idx];
	throw Span::OutOfRange();
}

size_t Span::size() const
{
	return (this->_storage.size());
}

std::ostream	&operator<<(std::ostream &stream, const Span &other)
{
	stream << "[";
	for(size_t i = 0; i < other.size(); i++)
	{
		stream << other[i];
		if (i != other.size() - 1)
			stream << ", ";
	}
	stream << "]";
	return stream;
}
