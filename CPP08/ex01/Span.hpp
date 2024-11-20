/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:20:12 by fli               #+#    #+#             */
/*   Updated: 2024/11/20 17:22:40 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <exception>
# include <cmath>
# include <iostream>

class Span
{
	private:
		unsigned int _maxInt;
		std::vector<int> _storage;
		Span();

	public:
		~Span();
		Span(const Span &other);
		Span &operator=(const Span &other);

		Span(unsigned int maxInt);

		void addNumber(int toAdd);
		void addNumber(std::vector<int> toAdd);
		int shortestSpan();
		int longestSpan();

		size_t size() const;
		const int& operator[](size_t idx) const;

		class OutOfRange;
		class StorageFull;
		class NoSpanFound;
};


std::ostream	&operator<<(std::ostream &stream, const Span &other);

#endif
