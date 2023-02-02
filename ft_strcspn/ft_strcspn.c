/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:08:36 by pedperei          #+#    #+#             */
/*   Updated: 2023/01/09 15:20:41 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int		i;
	int		j;
	size_t	nbr;

	i = 0;
	j = 0;
	nbr = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (reject[j] != '\0')
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
        i++;
	}
    nbr = (size_t)i;
	return (nbr);
}

/* int	main(void)
{
	printf("%ld", ft_strcspn("test", "f"));
	printf("%ld", strcspn("test", "f"));
} */
