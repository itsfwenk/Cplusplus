/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:52:12 by fli               #+#    #+#             */
/*   Updated: 2024/11/27 19:49:05 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <exception>
# include <cmath>
# include <algorithm>
# include <limits>
# include <ctime>

void sortWithVector(std::vector<int> *toSort, std::vector<int> *sorted);
class PmergeMe
{
	private:
	std::vector<int> _input;
	std::vector<int> _sorted;
	std::vector<std::pair<int, int> > _pairs;

	std::deque<int> _dInput;
	std::deque<int> _dSorted;
	std::deque<std::pair<int, int> > _dPairs;
	// PmergeMe();

	public:
	// PmergeMe(std::vector<int> _input);
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe& operator=(const PmergeMe &other);

	void addInput(long long n, std::vector<int> *input);
	// std::pair<int, int> getPair(size_t index);
	// size_t getInputSize();
	// int getInput(size_t index);
	// int getSorted(size_t index);
	// void removePair(size_t index);
	// void addPairs();
	// void insertSort(int a);
	// void sortInput();

	static int getJacobsthal(int n);
	static bool isAllDigits(std::string str);
	static void checkInput(char **av);
	static std::vector<std::pair<int, int> >::iterator getPair(int toFind, std::vector<std::pair<int, int> > *pairs);
	static void makePairs(std::vector<int> toSort, std::vector<std::pair<int, int> > *pairs);
	static std::vector<int> makeNewList(std::vector<std::pair<int, int> > pairs);
	static void sortPairs(std::vector<std::pair<int, int> > *pairs);
	// static bool pairAdded(int n);
	// static std::vector<int>::iterator leftBetween(std::vector<std::pair<int, int> > *pairs, std::vector<int> *sorted, int start, int end);
	static std::vector<int>::iterator insertInSorted(std::vector<int> *sorted, int intToInsert, std::vector<std::pair<int, int> > *pairs, std::vector<std::pair<int, int> >::iterator pairToAdd);
	static void addRemainingPairs(std::vector<int> *sorted, std::vector<std::pair<int, int> > *pairs);
	static void jacobsthalInsert(std::vector<std::pair<int, int> > *pairs, std::vector<int> *sorted);

	// void dAddInput(long long n);
	// std::pair<int, int> dGetPair(size_t index);
	// size_t dGetInputSize();
	// int dGetInput(size_t index);
	// int dGetSorted(size_t index);
	// void dRemovePair(size_t index);
	// void dAddPairs();
	// void dInsertSort(int a);
	// void dSortInput();

	class InvalidParameters : public std::exception
	{
		const char *what() const throw()
		{
			return "error : invalid parameters";
		}
	};

	class CannotHaveDuplicates : public std::exception
	{
		const char *what() const throw()
		{
			return "error : cannot have duplicates";
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
