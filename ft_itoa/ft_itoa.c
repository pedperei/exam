/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:32:57 by pedperei          #+#    #+#             */
/*   Updated: 2023/02/01 23:43:02 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	count_digits(int nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		i++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	int		len;
	int		len1;
	char	*str_nbr;
	int		i;

	i = 0;
	len = count_digits(nbr);
	len1 = count_digits(nbr);
	if (nbr == -2147483648)
		return ("-2147483648");
	else if (nbr == 0)
		return ("0");
	else
	{
		str_nbr = (char *)malloc((len + 1) * (sizeof(char)));
		if (!str_nbr)
			return (0);
		if (nbr < 0)
		{
			str_nbr[0] = '-';
			nbr = -nbr;
		}
		len--;
		while (nbr > 0)
		{
			str_nbr[len] = (nbr % 10) + '0';
			nbr /= 10;
			len--;
		}
		str_nbr[len1] = '\0';
		return (str_nbr);
	}
}
