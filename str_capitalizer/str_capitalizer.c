/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:47:36 by pedperei          #+#    #+#             */
/*   Updated: 2023/01/09 22:11:08 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	capitalizer(char c, int pos)
{
	if (c >= 'a' && c <= 'z' && pos == 1)
		c -= 32;
	else if (c >= 'A' && c <= 'Z' && pos == 1)
		c;
	else if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

int	is_space_tab(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		pos;
	char	c;

	i = 1;
	pos = 1;
	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	else
	{
		while (argv[i] != 0)
		{
			j = 0;
			pos = 1;
			while (is_space_tab(argv[i][j]))
			{
				write(1, &argv[i][j], 1);
				j++;
			}
			while (argv[i][j] != '\0')
			{
				c = capitalizer(argv[i][j], pos);
				write(1, &c, 1);
				pos = 0;
				if (is_space_tab(c))
					pos = 1;
				j++;
			}
			i++;
			write(1, "\n", 1);
		}
	}
}
