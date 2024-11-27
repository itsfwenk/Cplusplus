/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:52:11 by fli               #+#    #+#             */
/*   Updated: 2024/11/27 21:16:02 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// void printAllPairs(std::vector <std::pair<int, int> > pairs)
// {
// 	for (std::vector <std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
// 	{
// 		std::cout << it->first << " " << it->second << std::endl;
// 	}
// }

// void printList(std::vector <int> *list)
// {
// 	std::cout << "list size = " << list->size() << std::endl;
// 	for (std::vector <int>::iterator it = list->begin(); it != list->end(); it++)
// 	{
// 		std::cout << *it << " ";
// 	}
// 	std::cout << std::endl;
// }

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return *this;
}

void PmergeMe::addInput(long long n, std::vector<int> *input)
{
	if (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min())
		throw PmergeMe::InvalidParameters();
	if (input->size() == 0)
	{
		input->push_back(n);
		return ;
	}
	std::vector<int>::iterator it = std::find(input->begin(), input->end(), n);
	if (it != input->end())
		throw PmergeMe::CannotHaveDuplicates();
	input->push_back(n);
}

void PmergeMe::addInput(long long n, std::deque<int> *input)
{
	if (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min())
		throw PmergeMe::InvalidParameters();
	if (input->size() == 0)
	{
		input->push_back(n);
		return ;
	}
	std::deque<int>::iterator it = std::find(input->begin(), input->end(), n);
	if (it != input->end())
		throw PmergeMe::CannotHaveDuplicates();
	input->push_back(n);
}

int PmergeMe::getJacobsthal(int n)
{
	if (n == 0)
		return (0);

	return ((pow(2, n) - pow(-1, n)) / 3);
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

std::vector<std::pair<int, int> >::iterator PmergeMe::getPair(int toFind, std::vector<std::pair<int, int> > *pairs)
 {
	for (std::vector<std::pair<int, int> >::iterator it = pairs->begin(); it != pairs->end(); it++)
	{
		if (it->first == toFind || it->second == toFind)
		{
			// std::cout << "returned pair is " << it->first << " " << it->second << std::endl;
			return it;
		}
	}
	throw OutOfRange();
 }

void PmergeMe::makePairs(std::vector<int> toSort, std::vector<std::pair<int, int> > *pairs)
{
	int a;
	int b;
	int j = 0;
	for (size_t i = 0; i < toSort.size() / 2; i++)
	{
		// std::cout << "SIZE = " << toSort.size() / 2 << std::endl;
		// std::cout << "i = " << i << std::endl;
		a = toSort[i + j];
		b = toSort[i + j + 1];
		pairs->push_back(std::make_pair(a, b));
		j++;
	}
}

std::vector<int> PmergeMe::makeNewList(std::vector<std::pair<int, int> > pairs)
{
	std::vector<int> newList;

	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it < pairs.end(); it++)
	{
		newList.push_back(it->second);
	}
	return newList;
}

void PmergeMe::sortPairs(std::vector<std::pair<int, int> > *pairs)
{
	for (std::vector<std::pair<int, int> >::iterator it = pairs->begin(); it != pairs->end(); it++)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
}

std::vector<int>::iterator PmergeMe::insertInSorted(std::vector<int> *sorted, int intToInsert, std::vector<std::pair<int, int> > *pairs, std::vector<std::pair<int, int> >::iterator pairToAdd)
{
	std::vector<int>::iterator it = std::upper_bound(sorted->begin(), sorted->end(), intToInsert);
	sorted->insert(it, intToInsert);
	pairs->erase(pairToAdd);
	return it;
}

void PmergeMe::addRemainingPairs(std::vector<int> *sorted, std::vector<std::pair<int, int> > *pairs)
{
	while (pairs->size() > 0)
	{
		std::vector<std::pair<int, int> >::iterator pairToAdd = pairs->begin();
		int intToInsert = pairToAdd->first;
		std::vector<int>::iterator it = std::upper_bound(sorted->begin(), sorted->end(), intToInsert);
		sorted->insert(it, intToInsert);
		pairs->erase(pairToAdd);
	}
}

void PmergeMe::jacobsthalInsert(std::vector<std::pair<int, int> > *pairs, std::vector<int> *sorted)
{
	std::vector<int> initial_list = *sorted;
	size_t pairvecsize = pairs->size();

	// printAllPairs(*pairs);
	std::vector <std::pair<int, int> >::iterator pairToAdd;
	try
	{
		pairToAdd = PmergeMe::getPair(sorted->front(), pairs);
	}
	catch (const std::exception& e)
	{
		std::cerr << "error : no pair with such value" << std::endl;
		exit(EXIT_FAILURE);
	}
	sorted->insert(sorted->begin(), pairToAdd->first);
	pairs->erase(pairToAdd);
	int i = 3;
	while (pairs->size() != 0)
	{
		try
		{
			size_t jac = PmergeMe::getJacobsthal(i);
			// std::cout << "---JACOB = " << jac << std::endl;
			if (jac > pairvecsize)
				break;
			pairToAdd = PmergeMe::getPair(initial_list[jac - 1], pairs);
		}
		catch (const std::exception& e)
		{
			std::cerr << "error : no pair with such value" << std::endl;
			exit(EXIT_FAILURE);
		}
		// std::cout << "pair to add first = " << pairToAdd->first << "pair to add second = " << pairToAdd->second << std::endl;
		int intToInsert = pairToAdd->first;

		std::vector<int>::iterator subEnd = std::find(initial_list.begin(), initial_list.end(), pairToAdd->second);
		// std::cout << "subEnd is " << *subEnd << std::endl;
		std::vector<int> subList(initial_list.begin(), subEnd);

		std::vector<int>::iterator it = std::upper_bound(sorted->begin(), sorted->end(), intToInsert);
		// std::cout << "it is " << *it << std::endl;
		sorted->insert(it, intToInsert);
		pairs->erase(pairToAdd);
		// std::cout << "inital list = ";
		// printList(&initial_list);
		// std::cout << "+++++++++++++pair to add second = " << pairToAdd->second << std::endl;
		// std::vector<int>::iterator subEnd = std::find(initial_list.begin(), initial_list.end(), pairToAdd->second);
		// std::cout << "subEnd is " << *subEnd << std::endl;
		// std::vector<int> subList(initial_list.begin(), subEnd);
		// std::cout << "sublist = ";
		// printList(&subList);
		for (std::vector<int>::iterator it = subList.begin(); it != subList.end(); it++)
		{
			try
			{
				pairToAdd = PmergeMe::getPair(*it, pairs);
				intToInsert = pairToAdd->first;
				insertInSorted(sorted, intToInsert, pairs, pairToAdd);
			}
			catch(const std::exception& e)
			{
				continue;
			}
		}
		i++;
	}
	addRemainingPairs(sorted, pairs);
}
// static int iteration = 0;

void sortWithVector(std::vector<int> *toSort, std::vector<int> *sorted)
{
	if (toSort->size() <= 1)
		return;
	// std::cout << "iteration : " << iteration << std::endl;
	// iteration++;
	// std::cout << toSort->size() << std::endl;
	// std::cout << "-------" <<std::endl;
	// for (std::vector<int>::iterator it = toSort->begin(); it != toSort->end(); it++)
	// {
	// 	std::cout << *it << " ";

	// }
	// std::cout << std::endl;
	// std::cout << "-------" <<std::endl;
	if (toSort->size() < 2)
		return ;
	std::vector<std::pair<int, int> > pairs;
	PmergeMe::makePairs(*toSort, &pairs);
	PmergeMe::sortPairs(&pairs);
	if (pairs.size() == 1)
	{
		sorted->push_back(pairs[0].first);
		sorted->push_back(pairs[0].second);
		if (toSort->size() == 3)
		{
			std::vector<int>::iterator it = std::upper_bound(sorted->begin(), sorted->end(), toSort->back());
			sorted->insert(it, toSort->back());
		}
		return;
	}
	// for (size_t i = 0; i < pairs.size(); i++)
	// {
	// 	std::cout << pairs[i].first << " " << pairs[i].second << std::endl;
	// }
	std::vector<int> newList = PmergeMe::makeNewList(pairs);
	sortWithVector(&newList, sorted);
	PmergeMe::jacobsthalInsert(&pairs, sorted);
	if (toSort->size() % 2 == 1)
	{
		int unpaired = toSort->back();
		std::vector<int>::iterator it = std::upper_bound(sorted->begin(), sorted->end(), unpaired);
		sorted->insert(it, unpaired);
	}
}



//////////////////////////////////////////////////////////////////////////////////

std::deque<std::pair<int, int> >::iterator PmergeMe::getPair(int toFind, std::deque<std::pair<int, int> > *pairs)
{
	for (std::deque<std::pair<int, int> >::iterator it = pairs->begin(); it != pairs->end(); it++)
	{
		if (it->first == toFind || it->second == toFind)
		{
			// std::cout << "returned pair is " << it->first << " " << it->second << std::endl;
			return it;
		}
	}
	throw OutOfRange();
}

void PmergeMe::makePairs(std::deque<int> toSort, std::deque<std::pair<int, int> > *pairs)
{
	int a;
	int b;
	int j = 0;
	for (size_t i = 0; i < toSort.size() / 2; i++)
	{
		// std::cout << "SIZE = " << toSort.size() / 2 << std::endl;
		// std::cout << "i = " << i << std::endl;
		a = toSort[i + j];
		b = toSort[i + j + 1];
		pairs->push_back(std::make_pair(a, b));
		j++;
	}
}

std::deque<int> PmergeMe::makeNewList(std::deque<std::pair<int, int> > pairs)
{
	std::deque<int> newList;

	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it < pairs.end(); it++)
	{
		newList.push_back(it->second);
	}
	return newList;
}

void PmergeMe::sortPairs(std::deque<std::pair<int, int> > *pairs)
{
	for (std::deque<std::pair<int, int> >::iterator it = pairs->begin(); it != pairs->end(); it++)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
}

std::deque<int>::iterator PmergeMe::insertInSorted(std::deque<int> *sorted, int intToInsert, std::deque<std::pair<int, int> > *pairs, std::deque<std::pair<int, int> >::iterator pairToAdd)
{
	std::deque<int>::iterator it = std::upper_bound(sorted->begin(), sorted->end(), intToInsert);
	sorted->insert(it, intToInsert);
	pairs->erase(pairToAdd);
	return it;
}

void PmergeMe::addRemainingPairs(std::deque<int> *sorted, std::deque<std::pair<int, int> > *pairs)
{
	while (pairs->size() > 0)
	{
		std::deque<std::pair<int, int> >::iterator pairToAdd = pairs->begin();
		int intToInsert = pairToAdd->first;
		std::deque<int>::iterator it = std::upper_bound(sorted->begin(), sorted->end(), intToInsert);
		sorted->insert(it, intToInsert);
		pairs->erase(pairToAdd);
	}
}

void PmergeMe::jacobsthalInsert(std::deque<std::pair<int, int> > *pairs, std::deque<int> *sorted)
{
	std::deque<int> initial_list = *sorted;
	size_t pairvecsize = pairs->size();

	// printAllPairs(*pairs);
	std::deque <std::pair<int, int> >::iterator pairToAdd;
	try
	{
		pairToAdd = PmergeMe::getPair(sorted->front(), pairs);
	}
	catch (const std::exception& e)
	{
		std::cerr << "error : no pair with such value" << std::endl;
		exit(EXIT_FAILURE);
	}
	sorted->insert(sorted->begin(), pairToAdd->first);
	pairs->erase(pairToAdd);
	int i = 3;
	while (pairs->size() != 0)
	{
		try
		{
			size_t jac = PmergeMe::getJacobsthal(i);
			// std::cout << "---JACOB = " << jac << std::endl;
			if (jac > pairvecsize)
				break;
			pairToAdd = PmergeMe::getPair(initial_list[jac - 1], pairs);
		}
		catch (const std::exception& e)
		{
			std::cerr << "error : no pair with such value" << std::endl;
			exit(EXIT_FAILURE);
		}
		// std::cout << "pair to add first = " << pairToAdd->first << "pair to add second = " << pairToAdd->second << std::endl;
		int intToInsert = pairToAdd->first;

		std::deque<int>::iterator subEnd = std::find(initial_list.begin(), initial_list.end(), pairToAdd->second);
		// std::cout << "subEnd is " << *subEnd << std::endl;
		std::deque<int> subList(initial_list.begin(), subEnd);

		std::deque<int>::iterator it = std::upper_bound(sorted->begin(), sorted->end(), intToInsert);
		// std::cout << "it is " << *it << std::endl;
		sorted->insert(it, intToInsert);
		pairs->erase(pairToAdd);
		// std::cout << "inital list = ";
		// printList(&initial_list);
		// std::cout << "+++++++++++++pair to add second = " << pairToAdd->second << std::endl;
		// std::deque<int>::iterator subEnd = std::find(initial_list.begin(), initial_list.end(), pairToAdd->second);
		// std::cout << "subEnd is " << *subEnd << std::endl;
		// std::deque<int> subList(initial_list.begin(), subEnd);
		// std::cout << "sublist = ";
		// printList(&subList);
		for (std::deque<int>::iterator it = subList.begin(); it != subList.end(); it++)
		{
			try
			{
				pairToAdd = PmergeMe::getPair(*it, pairs);
				intToInsert = pairToAdd->first;
				insertInSorted(sorted, intToInsert, pairs, pairToAdd);
			}
			catch (const std::exception& e)
			{
				continue;
			}
		}
		i++;
	}
	addRemainingPairs(sorted, pairs);
}
// static int iteration = 0;

void sortWithDeque(std::deque<int> *toSort, std::deque<int> *sorted)
{
	if (toSort->size() <= 1)
		return;
	// std::cout << "iteration : " << iteration << std::endl;
	// iteration++;
	// std::cout << toSort->size() << std::endl;
	// std::cout << "-------" <<std::endl;
	// for (std::deque<int>::iterator it = toSort->begin(); it != toSort->end(); it++)
	// {
	// 	std::cout << *it << " ";

	// }
	// std::cout << std::endl;
	// std::cout << "-------" <<std::endl;
	if (toSort->size() < 2)
		return ;
	std::deque<std::pair<int, int> > pairs;
	PmergeMe::makePairs(*toSort, &pairs);
	PmergeMe::sortPairs(&pairs);
	if (pairs.size() == 1)
	{
		sorted->push_back(pairs[0].first);
		sorted->push_back(pairs[0].second);
		if (toSort->size() == 3)
		{
			std::deque<int>::iterator it = std::upper_bound(sorted->begin(), sorted->end(), toSort->back());
			sorted->insert(it, toSort->back());
		}
		return;
	}
	// for (size_t i = 0; i < pairs.size(); i++)
	// {
	// 	std::cout << pairs[i].first << " " << pairs[i].second << std::endl;
	// }
	std::deque<int> newList = PmergeMe::makeNewList(pairs);
	sortWithDeque(&newList, sorted);
	PmergeMe::jacobsthalInsert(&pairs, sorted);
	if (toSort->size() % 2 == 1)
	{
		int unpaired = toSort->back();
		std::deque<int>::iterator it = std::upper_bound(sorted->begin(), sorted->end(), unpaired);
		sorted->insert(it, unpaired);
	}
}
