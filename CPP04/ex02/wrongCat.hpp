/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:56:58 by fli               #+#    #+#             */
/*   Updated: 2024/11/06 15:07:28 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "wrongAnimal.hpp"

class wrongCat : public wrongAnimal
{
	private:
	protected:
	public:
		wrongCat();
		~wrongCat();
		wrongCat(const wrongCat &other);
		wrongCat& operator=(const wrongCat &other);

		void makeSound(void) const;
		std::string getType() const;
};

// class wrongDgo : public wrongAnimal
// {
// 	private:
// 	protected:
// 	public:
// 		wrongDgo();
// 		~wrongDgo();
// 		wrongDgo(const wrongDgo &other);
// 		wrongDgo& operator=(const wrongDgo &other);
// };

#endif
