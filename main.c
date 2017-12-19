/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:53:35 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/12/18 15:05:04 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	int		i;
	char	buf[BUF_SIZE + 1];
	char	**pdt;
	t_tetri *listtetri;
	t_misc	s;

	s.a = 0;
	s.b = 0;
	s.c = 0;
	s.d = 0;
	s.e = -1;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if ((pdt = ft_create_table(buf, ret)) == 0)
		return (0);
	if (check_valid(argc, argv) == 1)
		return (1);
	listtetri = ft_ret_tet(buf, ret);
	ret = ft_find_longest(pdt);
	fd = ft_find_highest(pdt);
	s.n = size_square(listtetri[0].nbr, fd, ret);
	pdt = resolve_recursive(s, listtetri);
	ft_putstr_improved(pdt, s.n + 1);
	return (0);
}
