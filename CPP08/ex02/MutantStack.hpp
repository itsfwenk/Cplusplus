/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:55:09 by fli               #+#    #+#             */
/*   Updated: 2024/11/20 19:58:00 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
	public:
		MutantStack() : std::stack<T>() {};
		~MutantStack() {};
		MutantStack (const MutantStack &other) :
		{
			this->c = other.c;
		};
		MutantStack & operator=(const MutantStack &value)
		{
			if (this != &other)
			{
				this->c = other.c;
			}
			return *this;
		};

		typedef typename std::deque<T>::iterator		iterator;
		typedef typename std::deque<T>::const_iterator	const_iterator;
		const const_iterator begin() const;
		const const_iterator end() const;
		iterator begin();
		iterator end();
};

#endif
