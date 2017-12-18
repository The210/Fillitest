/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:12:40 by dhorvill          #+#    #+#             */
/*   Updated: 2017/12/17 23:43:21 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char			**ft_create_table(char *buf, int ret)
{
	int		i;
	char	new_str[ret];
	char	**new_table;

	i = -1;
	ft_strcpy(new_str, buf);
	while (new_str[++i])
	{
		if (new_str[i] == '\n' && new_str[i + 1] == '\n')
		{
			new_str[i] = ' ';
			new_str[i + 1] = ' ';
		}
	}
	new_table = ft_strsplit(new_str, ' ');
	return (new_table);
}

static t_tetri	ft_fill_tetri(char **t, t_tetri tetrimino)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	j = 0;
	while (k < 3)
	{
		while (k < 3)
		{
			while (t[i][j] && t[i][j] != '#')
				j++;
			if (t[i][j] != '#')
			{
				i++;
				j = 0;
			}
			if (t[i][j] == '#')
			{
				if ((t[i + 1] && t[i + 1][j] == '#' && t[i + 1][j - 2] == '#')
					|| (t[i][j - 2] == '#' && t[i + 1][j - 2] == '#'))
				{
					j = j - 2;
					i++;
					tetrimino.coord[k] = 'P';
				}
				else if (t[i][j + 1] == '#')
				{
					j++;
					tetrimino.coord[k] = 'R';
				}
				else if (t[i + 1][j - 1] == '#')
				{
					i++;
					j--;
					tetrimino.coord[k] = 'Z';
				}
				else if (t[i + 1][j] == '#')
				{
					i++;
					tetrimino.coord[k] = 'D';
				}
				else if (t[i + 1][j + 1] == '#')
				{
					tetrimino.coord[k] = 'X';
					i++;
					j++;
				}
				else if (t[i][j - 1] == '#')
				{
					j--;
					tetrimino.coord[k] = 'L';
				}
				k++;
			}
		}
	}
	return (tetrimino);
}

static t_tetri	ft_fill_height(t_tetri tetrimino)
{
	int i;
	int height;

	i = 0;
	height = 1;
	while (tetrimino.coord[i])
	{
		if (tetrimino.coord[i] == 'D' || tetrimino.coord[i] == 'X' ||
				tetrimino.coord[i] == 'Z')
			height++;
		i++;
	}
	tetrimino.height = height;
	return (tetrimino);
}

static t_tetri	*ft_fill_all_tetri(char **pdt, t_tetri *tetriminos, int nbr)
{
	int i;

	i = 0;
	while (pdt[i])
	{
		tetriminos[i] = ft_fill_tetri(ft_strsplit(pdt[i], '\n'), tetriminos[i]);
		tetriminos[i] = ft_fill_height(tetriminos[i]);
		tetriminos[i].nbr = nbr;
		tetriminos[i].coord[3] = i + 'A';
		i++;
	}
	return (tetriminos);
}

t_tetri			*ft_ret_tet(char *buf, int ret)
{
	char	**all_tetri;
	t_tetri	*tetri_tab;
	int		i;

	i = 0;
	all_tetri = ft_create_table(buf, ret);
	while (all_tetri[i])
		i++;
	if ((tetri_tab = (t_tetri*)malloc(sizeof(t_tetri) * (i + 1))) == NULL)
		return (NULL);
	ft_fill_all_tetri(all_tetri, tetri_tab, i);
	return (tetri_tab);
}
