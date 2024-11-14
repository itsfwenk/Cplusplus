/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:04:03 by fli               #+#    #+#             */
/*   Updated: 2024/11/14 14:44:53 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

class Data
{
	private:
		int i;
	public:
		Data();
		~Data();
		Data(Data const &other);
		Data &operator=(Data const &other);
};

#endif
