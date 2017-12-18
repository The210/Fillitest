/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_recursive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:19:50 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/12/18 14:36:41 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char	**ft_strcpy_improved(char **dest, char **tab, t_misc s)
{	
	int i;
	int j;

	i = 0;
	while (tab[i])
		i++;
	if ((dest = malloc(sizeof(char*) * (i + 1))) == NULL)
		return (NULL);
	i = -1;
	while (++i < s.n)
	{
		j = 0;
		while (j < s.n)
			j++;
		if ((dest[i] = malloc(sizeof(char*) * (j + 1))) == NULL)
			return (NULL);
	}
	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
			dest[i][j] = tab[i][j];
	}
	return (dest);
}

t_misc	ft_find_spot_start(t_tetri tetriminos, char **tab, t_misc s)
{
	s.a = 0;
	s.b = 0;
	while (test_position(tetriminos, s, tab) == 1 && tab[s.a][s.b] != 'e')
	{
		s.b++;
		s = find_next_point(s, tab);
	}
/*	if (s.b == s.c && s.a == s.d)
	{
		s.b++;
		s = find_next_point(s, tab);
		while (test_position(tetriminos, s, tab) == 1 && tab[s.a][s.b] != 'e')
		{
			s.b++;
			s = find_next_point(s, tab);
		}
	}*/
	return (s);
}

t_misc	ft_find_spot(t_tetri tetriminos, char **tab, t_misc s)
{
	while (test_position(tetriminos, s, tab) == 1 && tab[s.a][s.b] != 'e')
	{
		s.b++;
		s = find_next_point(s, tab);
	}
	return (s);
}

t_misc		ft_double_test(char **tab, t_misc s, t_tetri *tetriminos)
{
	s.c = s.a;
	s.d = s.b;
	if (test_position(tetriminos[s.e], s, tab) == 0)
	{
		tab = draw_tetriminos(tetriminos[s.e], s, tab);
		s = ft_find_spot_start(tetriminos[s.e + 1], tab, s);
		if (test_position(tetriminos[s.e + 1], s, tab) == 0 && (s.e + 1) < tetriminos[0].nbr - 1)
		{
			s.p = 0;
			return (s);
		}
		else if (test_position(tetriminos[s.e + 1], s, tab) == 0)
		{
			tab = draw_tetriminos(tetriminos[s.e + 1], s, tab);
			s.p = 0;
			return (s);
		}
	}
	s.p = 1;
	return (s);
}

char	**combination_recursive(t_tetri *tetriminos, t_misc s, char **str)
{
	if (tetriminos[0].nbr == 1)
	{
		draw_tetriminos(tetriminos[0], s,  str);
		return (str);
	}
	if (s.e >= tetriminos[0].nbr - 1)
		return (str);
	s = ft_double_test(str, s, tetriminos);
	if (s.p == 0)
	{
		s.e++;
		if (s.e >= tetriminos[0].nbr - 1)
			return (str);
		return (combination_recursive(tetriminos, s, str));
	}
	else
	{
		s = ft_findcoord(str, s, tetriminos[s.e]);
		ft_erase(str, tetriminos[s.e]);
		s = ft_find_spot(tetriminos[s.e], str, s);
		while (s.e > 0 && s.a >= s.n)
		{
			s.e--;
			s = ft_findcoord(str, s, tetriminos[s.e]);
			ft_erase(str, tetriminos[s.e]);
			s = ft_find_spot(tetriminos[s.e], str, s);
		}
		if (s.e == 0 && s.a >= s.n)
			return (NULL);
		return (combination_recursive(tetriminos, s, str));
	}
	return (NULL);
}

char	**resolve_recursive(t_misc s, t_tetri *tetriminos)
{
	char	**str;

	s.a = 0;
	s.b = 0;
	s.e = 0;
	str = ft_tab(s.n);
	str = combination_recursive(tetriminos, s, str); 
	if (str != NULL)
		return (str);
	else
	{
		s.n++;
		return (resolve_recursive(s, tetriminos));
	}
}
