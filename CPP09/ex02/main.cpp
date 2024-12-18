
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:52:08 by fli               #+#    #+#             */
/*   Updated: 2024/11/24 16:53:39 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// int main(int ac, char **av)
// {
// 	(void)ac;

// 	PmergeMe test;
// 	std::cout << "SORT WITH VECTOR" << std::endl;
// 	try
// 	{
// 		std::clock_t start_time = std::clock();
// 		PmergeMe::checkInput(av);
// 		int i = 1;
// 		while (av[i])
// 		{
// 			test.addInput(std::atoll(av[i]));
// 			i++;
// 		}
// 		std::cout << "Before:    ";
// 		for (size_t i = 0; i < test.getInputSize(); i++)
// 		{
// 			std::cout << test.getInput(i) << " ";
// 			if (i > 4)
// 			{
// 				std::cout << "[...]";
// 				break;
// 			}
// 		}
// 		std::cout << std::endl;
// 		test.addPairs();
// 		test.sortInput();
// 		std::clock_t end_time = std::clock();
// 		std::cout << "After:     ";
// 		for (size_t i = 0; i < test.getInputSize(); i++)
// 		{
// 			std::cout << test.getSorted(i) << " ";
// 			if (i > 4)
// 			{
// 				std::cout << "[...]";
// 				break;
// 			}
// 		}
// 		std::cout << std::endl;
// 		std::cout << "Time to process a range of " << test.getInputSize();
// 		std::cout << " elements with std::vector : ";
// 		std::cout << double(end_time - start_time) / CLOCKS_PER_SEC * 1000000;
// 		std::cout << " us" << std::endl;
// 	}
// 	catch (const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}


// 	std::cout << std::endl << "SORT WITH DEQUE" << std::endl;

// 	try
// 	{
// 		std::clock_t start_time = std::clock();
// 		PmergeMe::checkInput(av);
// 		int i = 1;
// 		while (av[i])
// 		{
// 			test.dAddInput(std::atoll(av[i]));
// 			i++;
// 		}
// 		std::cout << "Before:    ";
// 		for (size_t i = 0; i < test.dGetInputSize(); i++)
// 		{
// 			std::cout << test.dGetInput(i) << " ";
// 			if (i > 4)
// 			{
// 				std::cout << "[...]";
// 				break;
// 			}
// 		}
// 		std::cout << std::endl;
// 		test.dAddPairs();
// 		test.dSortInput();
// 		std::clock_t end_time = std::clock();
// 		std::cout << "After:     ";
// 		for (size_t i = 0; i < test.dGetInputSize(); i++)
// 		{
// 			std::cout << test.dGetSorted(i) << " ";
// 			if (i > 4)
// 			{
// 				std::cout << "[...]";
// 				break;
// 			}
// 		}
// 		std::cout << std::endl;
// 		std::cout << "Time to process a range of " << test.dGetInputSize();
// 		std::cout << " elements with std::deque : ";
// 		std::cout << double(end_time - start_time) / CLOCKS_PER_SEC * 1000000;
// 		std::cout << " us" << std::endl;
// 	}
// 	catch (const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// }

int main(int ac, char **av)
{
	(void)ac;

	std::vector<int> sorted;
	std::vector<int> input;
	std::cout << "SORT WITH VECTOR" << std::endl;
	try
	{
		std::clock_t start_time = std::clock();
		PmergeMe::checkInput(av);
		int i = 1;
		while (av[i])
		{
			PmergeMe::addInput(std::atoll(av[i]), &input);
			i++;
		}
		std::cout << "Before:    ";
		for (size_t i = 0; i < input.size(); i++)
		{
			std::cout << input[i] << " ";
			if (i > 4)
			{
				std::cout << "[...]";
				break;
			}
		}
		std::cout << std::endl;

		sortWithVector(&input, &sorted);
		std::clock_t end_time = std::clock();
		std::cout << "After:     ";
		for (size_t i = 0; i < input.size(); i++)
		{
			std::cout << sorted[i] << " ";
			if (i > 4)
			{
				std::cout << "[...]";
				break;
			}
		}
		std::cout << std::endl;
		std::cout << "Time to process a range of " << input.size();
		std::cout << " elements with std::vector : ";
		std::cout << double(end_time - start_time) / CLOCKS_PER_SEC * 1000000;
		std::cout << " us" << std::endl;

		std::vector<int> vec(input.begin(), input.end());
		std::sort(vec.begin(), vec.end());
		if (vec == sorted)
			std::cout << "Sorted succesfully!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::deque<int> dsorted;
	std::deque<int> dinput;
	std::cout << "SORT WITH DEQUE" << std::endl;
	try
	{
		std::clock_t start_time = std::clock();
		PmergeMe::checkInput(av);
		int i = 1;
		while (av[i])
		{
			PmergeMe::addInput(std::atoll(av[i]), &dinput);
			i++;
		}
		std::cout << "Before:    ";
		for (size_t i = 0; i < dinput.size(); i++)
		{
			std::cout << dinput[i] << " ";
			if (i > 4)
			{
				std::cout << "[...]";
				break;
			}
		}
		std::cout << std::endl;

		sortWithDeque(&dinput, &dsorted);
		std::clock_t end_time = std::clock();
		std::cout << "After:     ";
		for (size_t i = 0; i < dinput.size(); i++)
		{
			std::cout << dsorted[i] << " ";
			if (i > 4)
			{
				std::cout << "[...]";
				break;
			}
		}
		std::cout << std::endl;
		std::cout << "Time to process a range of " << dinput.size();
		std::cout << " elements with std::deque : ";
		std::cout << double(end_time - start_time) / CLOCKS_PER_SEC * 1000000;
		std::cout << " us" << std::endl;

		std::deque<int> deq(dinput.begin(), dinput.end());
		std::sort(deq.begin(), deq.end());
		if (deq == dsorted)
			std::cout << "Sorted succesfully!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
