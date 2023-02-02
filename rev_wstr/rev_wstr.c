/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:10:36 by pedperei          #+#    #+#             */
/*   Updated: 2023/01/09 14:22:38 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	count_words(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		while (str[i] == '\t' || str[i] == ' ')
			i++;
		while (str[i] != '\t' && str[i] != ' ' && str[i] != '\0')
			i++;
		j++;
	}
	return (j);
}

char	*str_alloc(char *str, int pos)
{
	int		i;
	int		j;
	int		k;
	int		m;
	int		len;
	char	*str2;

	i = 0;
	j = 0;
	k = 0;
	len = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
        len = 0;
		while (str[i] == '\t' || str[i] == ' ')
			i++;
		k = i;
		while (str[i] != '\t' && str[i] != ' ' && str[i] != '\0')
		{
			i++;
			len++;
		}
		j++;
		if (j == pos)
		{
			m = 0;
			str2 = (char *)malloc(len + 1 * (sizeof(char)));
			while (str[k] != '\t' && str[k] != ' ' && str[k] != '\0')
			{
				str2[m] = str[k];
				k++;
                m++;
			}
			str2[m] = '\0';
            return(str2);
		}
        i++;
	}
	return (0);
}

void	write_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int i;
	int words;
	char **str;

	i = 0;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	else
	{
		words = count_words(argv[1]);
		str = (char **)malloc((words + 1) * (sizeof(char *)));
		if (!str)
			return (0);
		while (i < words)
		{
            i++;
			str[i - 1] = str_alloc(argv[1], i);
		}
		str[i] = 0;
	}
    i = count_words(argv[1]) - 1;
	while (i  >= 0)
	{
		write_str(str[i]);
        if(i != 0)
		    write(1, " ", 1);
		i--;
	}
	write(1, "\n", 1);
}