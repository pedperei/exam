/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 20:38:56 by pedperei          #+#    #+#             */
/*   Updated: 2023/01/08 22:28:41 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	is_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	is_space(char c)
{
	if (c == '\t' || c == ' ')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int i;
	int j;
	char c;

	i = 1;
	if (argc == 1)
		write(1, "\n", 1);
	else
	{
		while (argv[i] != 0)
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				while (is_space(argv[i][j]))
				{
					c = argv[i][j];
					write(1, &c, 1);
					j++;
				}
				while (!(is_space(argv[i][j])) && argv[i][j] != '\0')
				{
					if (is_upper(argv[i][j]))
					{
						if (is_space(argv[i][j + 1]) || argv[i][j + 1] == '\0')
						{
							c = argv[i][j];
							//write(1, &c, 1);
						}
						else
						{
							c = argv[i][j] + 32;
							write(1, &c, 1);
						}
					}
					else if (!is_space(argv[i][j + 1]) && !argv[i][j
							+ 1] == '\0')
					{
						c = argv[i][j];
						write(1, &c, 1);
					}
					if ((is_space(argv[i][j + 1]) || argv[i][j + 1] == '\0'))
					{
						if (is_lower(argv[i][j]))
						{
							c = argv[i][j] - 32;
							write(1, &c, 1);
							j++;
							break ;
						}
						else
							write(1, &argv[i][j], 1);
					}
					j++;
				}
			}
			write(1, "\n", 1);
			i++;
		}
	}
}