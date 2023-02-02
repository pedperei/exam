/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:36:01 by pedperei          #+#    #+#             */
/*   Updated: 2023/01/17 17:49:00 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int a;
	int b;
	int c;
	if (argc != 3)
	{
		printf("\n");
		return (0);
	}
	else
	{
		a = atoi(argv[1]);
		b = atoi(argv[2]);
		if (a > b)
			c = b;
		else
			c = a;
		while (c > 0)
		{
			if ((a % c == 0) && (b % c == 0))
			{
				printf("%d\n", c);
				return (0);
			}
            c--;
		}
	}
}