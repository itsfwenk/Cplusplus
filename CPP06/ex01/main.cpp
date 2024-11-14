/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:00:16 by fli               #+#    #+#             */
/*   Updated: 2024/11/14 15:04:26 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serialize.hpp"
#include "Data.hpp"

int	main()
{
	Data data;
	uintptr_t serilized =  Serializer::serialize(&data);
	Data *deserilized = Serializer::deserialize(serilized);

	std::cout << "data adress : " << &data << std::endl;
	std::cout << "serialize : " << serilized << std::endl;
	std::cout << "deserialize : " << deserilized << std::endl;
}
