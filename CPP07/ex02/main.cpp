/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:00:18 by mli               #+#    #+#             */
/*   Updated: 2024/11/20 11:39:30 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete[] mirror;//
	return 0;
}

// int main()
// {
// 	Array<int>	arr(10);

// 	for (size_t i = 0; i < arr.size(); i++)
// 		arr[i] = i * 2;
// 	std::cout << arr << std::endl;

// 	std::cout << "\n" << "arr[10] = " << arr[5] << std::endl;

// 	try
// 	{
// 		std::cout << "arr[100] = " << arr[100] << std::endl;
// 	}
// 	catch (const std::exception& e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}

// 	Array<std::string> str(10);

// 	for (size_t i = 0; i < str.size(); i++)
// 		str[i] = "go";
// 	std::cout << "LENGTH: " << str.size() << std::endl;
// 	std::cout << str << std::endl;
// }
