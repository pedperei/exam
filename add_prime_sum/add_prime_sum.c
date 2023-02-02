/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:35:52 by pedperei          #+#    #+#             */
/*   Updated: 2023/01/09 13:09:01 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	convert_str_nbr(char *str)
{
	int	i;
	int	sinal;
	int	result;

	result = 0;
	sinal = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sinal = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sinal * result);
}

void	put_nbr(int nbr)
{
	char	c;

	c = 0;
	if (nbr > 9)
	{
		put_nbr(nbr / 10);
	}
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

int	is_prime(int nbr)
{
	int	i;

	i = 2;
	if (nbr == 1 || nbr == 2)
		return (1);
	while (i < nbr)
	{
		if (nbr % i == 0)
			return (0);
		i++;
	}
	return (1);
}

/* int main(int argc, char **argv)
{
    int i;
    i = 10;
    put_nbr(102132);
} */

int	main(int argc, char **argv)
{
	int i;
	int nbr;
	int result;

	i = 0;
	result = 0;
	if (argc != 2 || convert_str_nbr(argv[1]) <= 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	else
	{
		nbr = convert_str_nbr(argv[1]);
		while (nbr > 1)
		{
			if (is_prime(nbr))
				result += nbr;
			nbr--;
		}
	}
	put_nbr(result);
	write(1, "\n", 1);
}