/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:58:21 by pedperei          #+#    #+#             */
/*   Updated: 2023/01/16 20:29:46 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	wnbr(char *nbr)
{
	char	i;

	i = 0;
	while (nbr[i] != '\0')
	{
		write(1, &nbr[i], 1);
		i++;
	}
}

int	atoi(char *nbr)
{
	int	i;
	int	res;

	i = 0;
    res = 0;
	while (nbr[i] != '\0')
	{
		res = (res * 10) + (nbr[i] - '0');
		i++;
	}
	return (res);
}

void	putnbr(int n)
{
	char	c;

	if (n >= 10)
		putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int		i;
	char	c;
	int		res;

	i = 1;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	else
	{
		while (i < 10)
		{
			c = i + '0';
			write(1, &c, 1);
			write(1, " x ", 3);
			wnbr(argv[1]);
			write(1, " = ", 3);
			res = atoi(argv[1]) * i;
			putnbr(res);
			write(1, "\n", 1);
            i++;
		}
	}
}
