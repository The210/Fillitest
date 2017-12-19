/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findcoord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 22:08:24 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/12/18 22:48:33 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_misc	ft_findcoord(char **tab, t_misc *s, t_tetri tetrimino)
{
	int i;
	int j;
	int f;

	i = -1;
	f = 0;
	while (++i < s->n)
	{
		j = -1;
		while (++j < s->n)
		{
			if (tab[i][j] == tetrimino.coord[3])
			{
				f = 1;
				break ;
			}
		}
		if (f == 1)
			break ;
	}
	j++;
	if (f == 0)
	{
		i = 0;
		j = 1;
	}
	if (j >= s->n)
	{
		j = 0;
		i++;
	}
	s->a = i;
	s->b = j;
	return (*s);
}
