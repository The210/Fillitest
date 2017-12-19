/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_and_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:53:28 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/12/18 23:19:40 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_misc	find_next_point(t_misc s, char **tab)
{
	if (tab[s.a][s.b] == 'e')
	{
		s.a++;
		s.b = 0;
	}
	while (tab[s.a][s.b] != 'e' && tab[s.a][s.b] != '.')
	{
		while (tab[s.a + 1][s.b + 1] != 'e' && tab[s.a][s.b] != '.')
			s.b++;
		if (tab[s.a][s.b] != '.')
		{
			s.a++;
			s.b = 0;
		}
	}
	return (s);
}

int		test_position(t_tetri tetriminos, t_misc s, char **tab)
{
	int		count;
	int		k;
	int		m;
	int		n;

	k = 0;
	m = s.a;
	n = s.b;
	count = 0;
	while (tab[m][n] && count <= 3)
	{
		if (tab[m][n] == '.')
			count++;
		else
			break ;
		if (k <= 2)
		{
			if (tetriminos.coord[k] == 'P' && tab[m][n])
			{
				n = n - 2;
				m++;
				if (n < 0)
					return (1);
			}
			if (tetriminos.coord[k] == 'R' && tab[m][n])
				n++;
			if (tetriminos.coord[k] == 'D' && tab[m][n])
				m++;
			if (tetriminos.coord[k] == 'L' && tab[m][n])
			{
				n--;
				if (n < 0)
					return (1);
			}
			if (tetriminos.coord[k] == 'Z' && tab[m][n])
			{
				m++;
				n--;
				if (n < 0)
					return (1);
			}
			if (tetriminos.coord[k] == 'X' && tab[m][n])
			{
				m++;
				n++;
			}
			k++;
		}
		if ((count <= 3) && (n < 0))
			ft_putstr("ALERT\n");
	}
	if (count == 4)
		return (0);
	else
		return (1);
}

char	**draw_tetriminos(t_tetri tetriminos, t_misc s, char **tab)
{
	int k;
	int m;
	int n;

	m = s.a;
	n = s.b;
	k = 0;
	while (k <= 3)
	{
		tab[m][n] = tetriminos.coord[3];
		if (k <= 2)
		{
			if (tetriminos.coord[k] == 'P' && tab[m][n])
			{
				n = n - 2;
				m++;
			}
			if (tetriminos.coord[k] == 'R' && tab[m][n])
				n++;
			if (tetriminos.coord[k] == 'D' && tab[m][n])
				m++;
			if (tetriminos.coord[k] == 'L' && tab[m][n])
				n--;
			if (tetriminos.coord[k] == 'Z' && tab[m][n])
			{
				m++;
				n--;
			}
			if (tetriminos.coord[k] == 'X' && tab[m][n])
			{
				m++;
				n++;
			}
		}
		k++;
	}
	return (tab);
}
