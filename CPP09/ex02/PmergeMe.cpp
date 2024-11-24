/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:52:11 by fli               #+#    #+#             */
/*   Updated: 2024/11/25 00:10:10 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
	: _input(other._input), _sorted(other._sorted), _pairs(other._pairs), _dInput(other._dInput), _dSorted(other._dSorted), _dPairs(other._dPairs)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_input = other._input;
		this->_sorted = other._sorted;
		this->_pairs = other._pairs;
		this->_dInput = other._dInput;
		this->_dSorted = other._dSorted;
		this->_dPairs = other._dPairs;
	}
	return *this;
}

// PmergeMe::PmergeMe(std::vector<int> input) : _input(input)
// {
// }

void PmergeMe::addInput(long long n)
{
	if (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min())
		throw PmergeMe::InvalidParameters();
	if (this->_input.size() == 0)
	{
		this->_input.push_back(n);
		return ;
	}
	std::vector<int>::iterator it = std::find(this->_input.begin(), this->_input.end(), n);
	if (it != this->_input.end())
		throw PmergeMe::CannotHaveDuplicates();
	this->_input.push_back(n);
}

std::pair<int, int> PmergeMe::getPair(size_t index)
{
	if (this->_pairs.empty())
		throw PmergeMe::OutOfRange();
	int trueIndex = index % this->_pairs.size();
	return (this->_pairs[trueIndex]);
}

size_t PmergeMe::getInputSize()
{
	return (this->_input.size());
}

int PmergeMe::getInput(size_t index)
{
	if (index >= this->_input.size())
		throw PmergeMe::OutOfRange();
	return (this->_input[index]);
}

int PmergeMe::getSorted(size_t index)
{
	if (index >= this->_sorted.size())
		throw PmergeMe::OutOfRange();
	return (this->_sorted[index]);
}

void PmergeMe::removePair(size_t index)
{
	// if (index >= this->_pairs.size())
	// 	throw PmergeMe::OutOfRange();
	if (this->_pairs.empty())
		throw PmergeMe::OutOfRange();
	int trueIndex = index % this->_pairs.size();
	this->_pairs.erase(this->_pairs.begin() + trueIndex);
}

int PmergeMe::getJacobsthal(int n)
{
	if (n == 0)
		return (0);

	return ((pow(2, n) - pow(-1, n)) / 3);
}

void PmergeMe::addPairs()
{
	// if (a < 0 || b < 0)
	// 	throw PmergeMe::InvalidParameters();
	int a;
	int b;
	int j = 0;
	for (size_t i = 0; i < this->_input.size() / 2; i++)
	{
		a = this->_input[i + j];
		b = this->_input[i + j + 1];
		this->_pairs.push_back(std::make_pair(a, b));
		j++;
	}
}

bool PmergeMe::isAllDigits(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

void PmergeMe::insertSort(int a)
{
	std::vector<int>::iterator it = std::upper_bound(this->_sorted.begin(), this->_sorted.end(), a);
	// while (it != this->_sorted.end())
	// {
	// 	if (a < *it)
	// 	{
	// 		this->_sorted.insert(it, a);
	// 		return ;
	// 	}
	// 	it++;
	// }
	if (it == this->_sorted.end())
		this->_sorted.push_back(a);
	else
		this->_sorted.insert(it, a);

}

void PmergeMe::sortInput()
{
	size_t initSize = this->_pairs.size();
	for (size_t i = 0; i < initSize; i++)
	{
		std::pair<int, int> toInsert = PmergeMe::getPair(PmergeMe::getJacobsthal(i));
		int small = std::min(toInsert.first, toInsert.second);
		int big = std::max(toInsert.first, toInsert.second);
		// std::cout << toInsert.first << " " << toInsert.second << std::endl;
		if (this->_sorted.empty())
		{
			this->_sorted.push_back(small);
			this->_sorted.push_back(big);
			continue;
		}
		PmergeMe::insertSort(small);
		PmergeMe::insertSort(big);
		PmergeMe::removePair(i);
	}
	if (this->_input.size() % 2 == 1)
		PmergeMe::insertSort(this->_input[this->_input.size() - 1]);
}

void PmergeMe::checkInput(char **av)
{
	size_t i = 1;
	while (av[i])
	{
		if (!PmergeMe::isAllDigits(av[i]))
			throw PmergeMe::InvalidParameters();
		i++;
	}
}

void PmergeMe::dAddInput(long long n)
{
	if (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min())
		throw PmergeMe::InvalidParameters();
	if (this->_dInput.size() == 0)
	{
		this->_dInput.push_back(n);
		return ;
	}
	std::deque<int>::iterator it = std::find(this->_dInput.begin(), this->_dInput.end(), n);
	if (it != this->_dInput.end())
		throw PmergeMe::CannotHaveDuplicates();
	this->_dInput.push_back(n);
}

std::pair<int, int> PmergeMe::dGetPair(size_t index)
{
	if (this->_dPairs.empty())
		throw PmergeMe::OutOfRange();
	int trueIndex = index % this->_dPairs.size();
	return (this->_dPairs[trueIndex]);
}

size_t PmergeMe::dGetInputSize()
{
	return (this->_dInput.size());
}

int PmergeMe::dGetInput(size_t index)
{
	if (index >= this->_dInput.size())
		throw PmergeMe::OutOfRange();
	return (this->_dInput[index]);
}

int PmergeMe::dGetSorted(size_t index)
{
	if (index >= this->_dSorted.size())
		throw PmergeMe::OutOfRange();
	return (this->_dSorted[index]);
}

void PmergeMe::dRemovePair(size_t index)
{
	if (this->_dPairs.empty())
		throw PmergeMe::OutOfRange();
	int trueIndex = index % this->_dPairs.size();
	this->_dPairs.erase(this->_dPairs.begin() + trueIndex);
}

void PmergeMe::dAddPairs()
{
	int a;
	int b;
	int j = 0;
	for (size_t i = 0; i < this->_dInput.size() / 2; i++)
	{
		a = this->_dInput[i + j];
		b = this->_dInput[i + j + 1];
		this->_dPairs.push_back(std::make_pair(a, b));
		j++;
	}
}

void PmergeMe::dInsertSort(int a)
{
	std::deque<int>::iterator it = std::upper_bound(this->_dSorted.begin(), this->_dSorted.end(), a);
	if (it == this->_dSorted.end())
		this->_dSorted.push_back(a);
	else
		this->_dSorted.insert(it, a);
}

void PmergeMe::dSortInput()
{
	size_t initSize = this->_dPairs.size();
	for (size_t i = 0; i < initSize; i++)
	{
		std::pair<int, int> toInsert = PmergeMe::dGetPair(PmergeMe::getJacobsthal(i));
		int small = std::min(toInsert.first, toInsert.second);
		int big = std::max(toInsert.first, toInsert.second);
		if (this->_dSorted.empty())
		{
			this->_dSorted.push_back(small);
			this->_dSorted.push_back(big);
			continue;
		}
		PmergeMe::dInsertSort(small);
		PmergeMe::dInsertSort(big);
		PmergeMe::dRemovePair(i);
	}
	if (this->_input.size() % 2 == 1)
		PmergeMe::dInsertSort(this->_input[this->_input.size() - 1]);
}
