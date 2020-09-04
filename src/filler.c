/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 22:32:00 by sbrynn            #+#    #+#             */
/*   Updated: 2020/09/04 14:44:41 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	fr_size(t_fill *filler, char *line, int n)
{
	int	x;
	int	y;

	line += n;
	y = ft_atoi(line);
	while (*line && *line != ' ')
		line++;
	x = ft_atoi(line);
	if (n == 8)
	{
		filler->mx = x;
		filler->my = y;
	}
	else
	{
		filler->tx = x;
		filler->ty = y;
	}
}

int		fr_read(t_fill *filler, char *line)
{
	while (ft_get_next_line(0, &line) && (!filler->map || !filler->token))
	{
		if (line && !ft_strncmp(line, "Plateau", 7))
		{
			fr_size(filler, line, 8);
			free(line);
			line = NULL;
			fr_read_map(filler, line);
		}
		else if (line && !ft_strncmp(line, "Piece", 5))
		{
			fr_size(filler, line, 6);
			free(line);
			line = NULL;
			fr_read_token(filler, line);
			return (1);
		}
		else
			free(line);
	}
	return (filler->map != NULL && filler->token != NULL);
}

t_fill	*fr_init(char p)
{
	t_fill *filler;

	if (!(filler = (t_fill*)malloc(sizeof(t_fill))))
		return (NULL);
	filler->player = p - '0';
	filler->map = NULL;
	filler->token = NULL;
	filler->mx = 0;
	filler->my = 0;
	filler->tx = 0;
	filler->ty = 0;
	filler->x = 0;
	filler->y = 0;
	return (filler);
}

t_fill	*fr_free(t_fill *filler, int last)
{
	int		i;
	char	p;

	i = -1;
	p = filler->player + '0';
	while (++i < filler->my)
		free(filler->map[i]);
	i = -1;
	while (++i < filler->ty)
		free(filler->token[i]);
	free(filler->map);
	free(filler->token);
	free(filler);
	if (last)
		return (0);
	return (fr_init(p));
}

int		main(void)
{
	char	*line;
	t_fill	*filler;

	line = NULL;
	if (ft_get_next_line(0, &line)\
	&& line && !ft_strncmp(line, "$$$ exec p", 9)\
	&& (line[10] == '1' || line[10] == '2'))
	{
		filler = fr_init(line[10]);
		free(line);
		line = NULL;
		while (fr_read(filler, line))
		{
			fr_heat_map(filler);
			fr_find_place(filler);
			ft_printf("%d %d\n", filler->y, filler->x);
			filler = fr_free(filler, 0);
		}
		fr_free(filler, 1);
	}
	return (0);
}
