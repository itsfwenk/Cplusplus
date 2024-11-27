/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:22:10 by fli               #+#    #+#             */
/*   Updated: 2024/11/27 11:28:50 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void PmergeMe::insertInSorted(str::vector<int> *sorted, int inToInsert, std::vector<std::pair<int, int> > *pairs, std::pair<int, int> pairToAdd)
{
	std::vector<int>::iterator it = std::upper_bound(sorted->begin(), sorted->end(), intToInsert);
	sorted->insert(it, intToInsert);
	pairs->erase(pairToAdd);
}

void PmergeMe::jacobsthalInsert(std::vector<std::pair<int, int> > *pairs, std::vector<int> *sorted)
{
	std::vector<int> initial_list = *sorted;
	size_t pairvecsize = pairs->size();

	printAllPairs(*pairs);
	std::vector <std::pair<int, int> >::iterator pairToAdd;
	// try
	// {
	// 	pairToAdd = PmergeMe::getPair(sorted->front(), pairs);
	// }
	// catch (const std::exception& e)
	// {
	// 	std::cerr << "error : no pair with such value" << std::endl;
	// 	exit(EXIT_FAILURE);
	// }
	// sorted->insert(sorted->begin(), pairToAdd->first);
	// pairs->erase(pairToAdd);
	int i = 2;
	while (pairs->size() != 0)
	{
		try
		{
			size_t jac = PmergeMe::getJacobsthal(i);
			if (jac > pairvecsize)
				break;
			pairToAdd = PmergeMe::getPair(initial_list[jac - 1], pairs);
		}
		catch (const std::exception& e)
		{
			std::cerr << "error : no pair with such value" << std::endl;
			exit(EXIT_FAILURE);
		}
		int intToInsert = pairToAdd->first;
		insertInSorted(sorted, inToInsert, pairs, pairToAdd);
		std::vector<int> subList(initial_list.begin(), it);
		for (std::vector<int>::iterator it = subList.begin(); it != subList.end(); it++)
		{
			try
			{
				pairToAdd = PmergeMe::getPair(*it, pairs);
				intToInsert = pairToAdd->first;
				insertInSorted(sorted, inToInsert, pairs, pairToAdd);
			}
			catch(const std::exception& e)
			{
				continue;
			}
		}
		i++;
	}
}
