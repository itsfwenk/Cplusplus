/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:52:37 by fli               #+#    #+#             */
/*   Updated: 2024/11/07 17:39:46 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	AAnimal	*animalArray[10];

	int i;
	for(i = 0; i < 5; i++)
		animalArray[i] = new Dog();
	for (i = 5; i < 10; i++)
		animalArray[i] = new Cat();

	for (i = 0; i < 10; i++)
		delete animalArray[i];

	// std::cout << "Lets copy a cat :" << std::endl;
	// Cat *cat1 = new Cat();
	// Cat *cat2 = new Cat();
	// *cat2 = *cat1;
	// delete cat1;
	// cat2->makeSound();

}


// int main()
// {
// const Animal* j = new Dog();
// const Animal* i = new Cat();
// delete j;//should not create a leak
// delete i;
// }
