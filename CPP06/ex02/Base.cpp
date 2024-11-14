/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:21:17 by fli               #+#    #+#             */
/*   Updated: 2024/11/14 18:10:56 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
}

Base * Base::generate(void)
{
	std::srand(std::time(0));

	int randomInt = (std::rand() % 3);
	Base* (*newABC[]) () =
	{
		&A::newA,
		&B::newB,
		&C::newC
	};
	return newABC[randomInt]();
}

void Base::identify(Base* p)
{
	Base *basePTR;

	if ((basePTR = dynamic_cast<A*>(p)))
		std::cout << "OMG it's an A class!" << std::endl;
	else if ((basePTR = dynamic_cast<B*>(p)))
		std::cout << "OMG it's an B class!" << std::endl;
	else if ((basePTR = dynamic_cast<C*>(p)))
		std::cout << "OMG it's an C class!" << std::endl;
	else
		std::cout << "cannot identify..." << std::endl;
}

void Base::identify(Base& p)
{
	try
	{
		A aPTR = dynamic_cast<A&>(p);
		std::cout << "OMG it's an A class!" << std::endl;
		return;
	}
	catch (const std::exception& e)
	{
	}
	try
	{
		B bPTR = dynamic_cast<B&>(p);
		std::cout << "OMG it's an B class!" << std::endl;
		return;
	}
	catch (const std::exception& e)
	{
	}
	try
	{
		C cPTR = dynamic_cast<C&>(p);
		std::cout << "OMG it's an C class!" << std::endl;
		return;
	}
	catch (const std::exception& e)
	{
		std::cout << "cannot identify..." << std::endl;
	}
}
