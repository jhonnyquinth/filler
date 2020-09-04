/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_heat_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 22:32:14 by sbrynn            #+#    #+#             */
/*   Updated: 2020/08/22 22:39:33 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		fr_abs(int x)
{
	return (x < 0 ? -x : x);
}

static int		fr_min_distance(t_fill *filler, int y, int x)
{
	int	i;
	int	j;
	int min_dist;
	int dist;

	i = 0;
	min_dist = -1;
	while (i < filler->my)
	{
		j = 0;
		while (j < filler->mx)
		{
			if (filler->map[i][j] == 0)
			{
				dist = fr_abs(i - y) + fr_abs(j - x);
				min_dist = dist < min_dist || min_dist == -1 ? dist : min_dist;
			}
			j++;
		}
		i++;
	}
	return (min_dist);
}

void			fr_heat_map(t_fill *filler)
{
	int	i;
	int	j;

	i = 0;
	while (i < filler->my)
	{
		j = 0;
		while (j < filler->mx)
		{
			if (filler->map[i][j] == -2)
				filler->map[i][j] = fr_min_distance(filler, i, j);
			j++;
		}
		i++;
	}
}
