/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:46:31 by mli               #+#    #+#             */
/*   Updated: 2024/11/17 14:18:27 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void	swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T	min(const T& a, const T& b)
{
	return b <= a ? b : a;
}

template <typename T>
T	max(const T& a, const T& b)
{
	return b >= a ? b : a;
}
