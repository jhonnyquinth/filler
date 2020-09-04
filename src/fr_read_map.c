/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 22:36:55 by sbrynn            #+#    #+#             */
/*   Updated: 2020/08/22 22:48:03 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		*fr_map_str(char *str, int n, int p_num)
{
	int		*arr;
	int		i;
	char	c;

	i = 0;
	c = p_num == 1 ? 'O' : 'X';
	if (!(arr = (int*)malloc(sizeof(int) * n)))
		return (NULL);
	while (i < n && str[i])
	{
		if (str[i] == '.')
			arr[i] = -2;
		else if (str[i] == c || str[i] == (c - 'A' + 'a'))
			arr[i] = -1;
		else
			arr[i] = 0;
		i++;
	}
	return (arr);
}

int				fr_read_map(t_fill *filler, char *line)
{
	int	i;

	i = 0;
	if (!(filler->map = (int**)malloc(sizeof(int*) * filler->my)))
		return (1);
	ft_get_next_line(0, &line);
	free(line);
	line = NULL;
	while (i < filler->my && ft_get_next_line(0, &line))
	{
		filler->map[i] = fr_map_str(line + 4, filler->mx, filler->player);
		free(line);
		line = NULL;
		i++;
	}
	return (0);
}
