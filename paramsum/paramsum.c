/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:02:10 by pedperei          #+#    #+#             */
/*   Updated: 2023/02/01 19:28:12 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	sinal;
	int	res;

	sinal = 1;
	i = 0;
	res = 0;
	if (str[i] == '-')
		sinal = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (sinal * res);
}

void	putnbr(int nbr)
{
	char	c;

	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
	}
	if (nbr >= 10)
		putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int i;
	int sum;

	i = 0;
	sum = 0;
	if (argc < 2)
	{
		write(1, "0\n", 2);
		return (0);
	}
	else
	{
		while (argv[i] != 0)
		{
			i++;
		}
		putnbr(i - 1);
	}
	write(1, "\n", 1);
}