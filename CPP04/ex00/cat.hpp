/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:56:58 by fli               #+#    #+#             */
/*   Updated: 2024/11/05 19:04:45 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "animal.hpp"

class Cat : public Animal
{
	private:
	protected:
	public:
		Cat();
		~Cat();
		Cat(const Cat &other);
		Cat& operator=(const Cat &other);
};

#endif
