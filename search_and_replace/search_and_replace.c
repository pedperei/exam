/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:46:07 by pedperei          #+#    #+#             */
/*   Updated: 2023/02/01 18:58:56 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int j;

	j = 0;
	if (argc != 4)
		write(1, "\n", 1);
	else if (argv[2][1] != '\0' || argv[3][1] != '\0')
		write(1, "\n", 1);
	else
	{
		while (argv[1][j] != '\0')
		{
			if (argv[1][j] == argv[2][0])
				write(1, &argv[3][0], 1);
			else
				write(1, &argv[1][j], 1);
			j++;
		}
		write(1, "\n", 1);
	}
}