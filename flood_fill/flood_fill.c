/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:12:44 by pedperei          #+#    #+#             */
/*   Updated: 2023/01/09 22:32:20 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

void	flood_fill_aux(char **tab, t_point size, t_point begin, char c)
{
	int	i;
	int	j;

	i = begin.y;
	j = begin.x;
	if (!(i >= 0 && i < size.y && j >= 0 && j < size.x))
		return ;
	if (tab[i][j] != c)
		return ;
	tab[i][j] = 'F';
	flood_fill_aux(tab, size, (t_point){begin.x + 1, begin.y}, c);
	flood_fill_aux(tab, size, (t_point){begin.x, begin.y + 1}, c);
	flood_fill_aux(tab, size, (t_point){begin.x - 1, begin.y}, c);
	flood_fill_aux(tab, size, (t_point){begin.x, begin.y - 1}, c);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	flood_fill_aux(tab, size, begin, tab[begin.y][begin.x]);
}

