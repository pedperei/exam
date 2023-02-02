/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:31:05 by pedperei          #+#    #+#             */
/*   Updated: 2023/02/01 23:26:27 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_whitepace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	countwords(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str && str[i] != '\0')
	{
		while (is_whitepace(str[i]))
			i++;
		while (str[i] != '\0' && !is_whitepace(str[i]))
			i++;
        if(!is_whitepace(str[i - 1]))
		    j++;
	}
	return (j);
}

char	*alloc_str(char *str, int pos)
{
	int		i;
	int		k;
	int		l;
	int		j;
	char	*word;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (is_whitepace(str[i]))
			i++;
		k = i;
		while (!is_whitepace(str[i]) && str[i] != '\0')
			i++;
		j++;
		if (j == pos)
		{
            l = 0;
            word = (char *)malloc((i - k + 1) * sizeof(char));
			while (k < i)
			{
				word[l] = str[k];
				k++;
				l++;
			}
			word[l] = '\0';
			return (word);
		}
	}
	return (0);
}

char	**ft_split(char *str)
{
	int		len;
	char	**split;
	int		i;

	len = countwords(str);
	i = 0;
	split = (char **)malloc((len + 1) * sizeof(char *));
	if (!split)
		return (0);
	while (i < len)
	{
		split[i] = alloc_str(str, i + 1);
		i++;
	}
	split[i] = 0;
	return (split);
}

/* int	main(void)
{
	char	**split;
	int		i;
	char	str[] = "three words apart    ";
	split = ft_split(str);
	i = 0;
    printf("%d", countwords(str));
	while (split[i] != 0)
	{
		printf("%s\n", split[i]);
		i++;
	}
} */