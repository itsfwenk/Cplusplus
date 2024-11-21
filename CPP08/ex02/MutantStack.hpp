/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:55:09 by fli               #+#    #+#             */
/*   Updated: 2024/11/21 11:10:07 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {};
		~MutantStack() {};
		MutantStack (const MutantStack &other): std::stack<T>()
		{
			this->c = other.c;
		};
		MutantStack & operator=(const MutantStack &other)
		{
			if (this != &other)
			{
				this->c = other.c;
			}
			return *this;
		};

		typedef typename std::deque<T>::iterator		iterator;
		typedef typename std::deque<T>::const_iterator	const_iterator;

		const const_iterator begin() const
		{
			return this->c.begin();
		};

		const const_iterator end() const
		{
			return this->c.end();
		};

		iterator begin()
		{
			return this->c.begin();
		};

		iterator end()
		{
			return this->c.end();
		};
};

#endif
