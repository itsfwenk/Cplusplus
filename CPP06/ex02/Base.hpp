/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:11:45 by fli               #+#    #+#             */
/*   Updated: 2024/11/14 18:13:09 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

class Base
{
	public:
		virtual ~Base();
		static Base * generate(void);
		static void identify(Base* p);
		static void identify(Base& p);
};

#endif
