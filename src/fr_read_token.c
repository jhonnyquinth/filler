/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_read_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 22:32:09 by sbrynn            #+#    #+#             */
/*   Updated: 2020/08/22 22:47:54 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		fr_read_token(t_fill *filler, char *line)
{
	int i;
	int j;

	i = 0;
	if (!(filler->token = (char**)malloc(sizeof(char*) * filler->ty)))
		return (1);
	while (i < filler->ty && ft_get_next_line(0, &line))
	{
		if (!(filler->token[i] = (char*)malloc(sizeof(char) * filler->tx)))
			return (1);
		j = -1;
		while (++j < filler->tx)
			filler->token[i][j] = line[j];
		i++;
		free(line);
	}
	return (0);
}
