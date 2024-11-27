/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:52:12 by fli               #+#    #+#             */
/*   Updated: 2024/11/27 21:17:25 by fli              ###   ########.fr       */
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
void sortWithDeque(std::deque<int> *toSort, std::deque<int> *sorted);
class PmergeMe
{
	private:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe& operator=(const PmergeMe &other);
	public:
	~PmergeMe();

	static void addInput(long long n, std::vector<int> *input);
	static void addInput(long long n, std::deque<int> *input);
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

	static std::deque<std::pair<int, int> >::iterator getPair(int toFind, std::deque<std::pair<int, int> > *pairs);
	static void makePairs(std::deque<int> toSort, std::deque<std::pair<int, int> > *pairs);
	static std::deque<int> makeNewList(std::deque<std::pair<int, int> > pairs);
	static void sortPairs(std::deque<std::pair<int, int> > *pairs);
	static std::deque<int>::iterator insertInSorted(std::deque<int> *sorted, int intToInsert, std::deque<std::pair<int, int> > *pairs, std::deque<std::pair<int, int> >::iterator pairToAdd);
	static void addRemainingPairs(std::deque<int> *sorted, std::deque<std::pair<int, int> > *pairs);
	static void jacobsthalInsert(std::deque<std::pair<int, int> > *pairs, std::deque<int> *sorted);

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
