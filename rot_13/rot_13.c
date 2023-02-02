/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:16:07 by pedperei          #+#    #+#             */
/*   Updated: 2023/01/17 16:24:57 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int i;
	char c;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	else
	{
		i = 0;
		while (argv[1][i] != '\0')
		{
			if ((argv[1][i] >= 'a' && argv[1][i] <= 'm') || (argv[1][i] >= 'A'
					&& argv[1][i] <= 'M'))
			{
				c = argv[1][i] + 13;
				write(1, &c, 1);
				i++;
			}
			else if ((argv[1][i] > 'm' && argv[1][i] <= 'z')
					|| (argv[1][i] > 'M' && argv[1][i] <= 'Z'))
			{
				c = argv[1][i] - 13;
				write(1, &c, 1);
				i++;
			}
			else
			{
				c = argv[1][i];
				write(1, &c, 1);
                i++;
			}
		}
        write(1,"\n",1);
	}
	return (0);
}