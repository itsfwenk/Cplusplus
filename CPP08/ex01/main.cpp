/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:16:55 by fli               #+#    #+#             */
/*   Updated: 2024/11/20 17:33:00 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// int main()
// {
// 	Span test = Span(10);
// 	std::vector<int> vec1;
// 	vec1.push_back(1);
// 	vec1.push_back(2);
// 	vec1.push_back(3);
// 	vec1.push_back(4);
// 	vec1.push_back(5);
// 	vec1.push_back(6);

// 	test.addNumber(vec1);
// 	std::cout << test << std::endl;

// 	test.addNumber(7);
// 	std::cout << test << std::endl;

// 	try
// 	{
// 		test.addNumber(vec1);
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}
// 	std::cout << "shortestSpan = " << test.shortestSpan() << std::endl;
// 	std::cout << "longestSpan = " << test.longestSpan() << std::endl;

// 	std::cout << "TEST 2" << std::endl;
// 	Span test2 = Span(10);
// 	try
// 	{
// 		std::cout << "shortestSpan = " << test2.shortestSpan() << std::endl;
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}
// 	try
// 	{
// 		std::cout << "test2[100] = " << test2[100] << std::endl;
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}
// 	test2.addNumber(10);
// 	test2.addNumber(20);
// 	test2.addNumber(90);
// 	test2.addNumber(9);
// 	std::cout << "shortestSpan = " << test2.shortestSpan() << std::endl;
// 	std::cout << "longestSpan = " << test2.longestSpan() << std::endl;
// }

int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
return 0;
}
