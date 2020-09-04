/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 22:49:23 by sbrynn            #+#    #+#             */
/*   Updated: 2020/08/22 22:50:49 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../lib/includes/header.h"

typedef struct		s_fill
{
	int				player;
	int				mx;
	int				my;
	int				tx;
	int				ty;
	int				x;
	int				y;
	int				**map;
	char			**token;
}					t_fill;
int					fr_read_map(t_fill *filler, char *line);
int					fr_read_token(t_fill *filler, char *line);
void				fr_heat_map(t_fill *filler);
void				fr_find_place(t_fill *filler);
#endif
