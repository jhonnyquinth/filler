/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_find_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 22:32:20 by sbrynn            #+#    #+#             */
/*   Updated: 2020/08/22 22:42:27 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	fr_in_map(t_fill *filler, int y, int x)
{
	if (y < filler->my && y >= 0 && x < filler->mx &&\
	x >= 0 && filler->map[y][x] != 0)
		return (1);
	return (0);
}

static int	fr_find(t_fill *filler, int y, int x)
{
	int	i;
	int	j;
	int	sum;
	int	cross_check;

	i = 0;
	sum = 0;
	cross_check = 0;
	while (i < filler->ty)
	{
		j = 0;
		while (j < filler->tx)
		{
			if (filler->token[i][j] == '*')
			{
				if (!fr_in_map(filler, y + i, x + j))
					return (-1);
				sum += filler->map[y + i][x + j];
				cross_check += filler->map[y + i][x + j] == -1 ? 1 : 0;
			}
			j++;
		}
		i++;
	}
	return (cross_check == 1 ? sum : -1);
}

void		fr_find_place(t_fill *filler)
{
	int	i;
	int	j;
	int sum;
	int min_sum;

	i = -(filler->ty);
	min_sum = 2147483647;
	while (i < (filler->ty + filler->my))
	{
		j = -(filler->tx);
		while (j < (filler->tx + filler->mx))
		{
			sum = fr_find(filler, i, j);
			if (sum != -1 && sum < min_sum)
			{
				min_sum = sum;
				filler->y = i;
				filler->x = j;
			}
			j++;
		}
		i++;
	}
}
