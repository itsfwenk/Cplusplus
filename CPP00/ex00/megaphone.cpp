/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:44:10 by fli               #+#    #+#             */
/*   Updated: 2024/08/05 23:56:25 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	ft_megaphone(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j] != '\0'; j++)
			argv[i][j] = toupper(argv[i][j]);
		std::cout << argv[i];
	}
	std::cout << "\n";
}

int		main(int argc, char **argv)
{
	ft_megaphone(argc, argv);
	return (0);
}