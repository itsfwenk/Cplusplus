/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:03:19 by fli               #+#    #+#             */
/*   Updated: 2024/11/20 14:15:38 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main()
{
	std::vector<int> vec;
	for (int i = 0; i <= 5; i++)
	{
		vec.push_back(i);
	}
	std::cout << *easyfind(vec, 4) << std::endl;
}
