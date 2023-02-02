/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:58:20 by pedperei          #+#    #+#             */
/*   Updated: 2023/01/09 15:03:41 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	reverse(char c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	else if (c >= 'A' && c <= 'Z')
		c = c + 32;
	write(1, &c, 1);
}

int	main(int agrc, char **agrv)
{
	int i;

	i = 0;
	if (agrc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (agrv[1][i] != '\0')
	{
		reverse(agrv[1][i]);
		i++;
	}
	write(1, "\n", 1);
}