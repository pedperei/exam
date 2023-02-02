/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:53:52 by pedperei          #+#    #+#             */
/*   Updated: 2023/01/16 21:14:44 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	putnbr(int n)
{
	char	c;

	if (n >= 10)
		putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	isprime(int n)
{
	int	i;

	i = 2;
	if (n == 1)
		return (0);
	while (n > i)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int i;
	int nbr;
	i = 2;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	else
	{
		nbr = atoi(argv[1]);
		while (nbr / i > 0)
		{
			if (isprime(i) && (nbr % i == 0))
			{
				putnbr(i);
				if (i != nbr)
					write(1, "*", 1);
                nbr /= i;
			}
            else
			    i++;
		}
        write(1,"\n",1);
	}
}