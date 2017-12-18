/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:53:30 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/12/18 00:45:18 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H
# define BUF_SIZE 600

typedef	struct	s_tetri
{
	char	coord[4];
	int		nbr;
	int		length;
	int		height;
}				t_tetri;

typedef struct	s_misc
{
	int		a;
	int		b;
	int		c;
	int		d;
	int		e;
	int		n;
	int		p;
}				t_misc;

int				ft_checks(int t2, int t3, char *b);
int				check_valid(int a, char **c);
int				ft_count_l(char **pdt, int highest);
t_tetri			*ft_ret_tet(char *buf, int ret);
int				ft_find_longest(char **p);
char			**ft_create_table(char *buf, int ret);
int				ft_find_highest(char **pdt);
void			ft_freestr(char **str);
int				ft_strcmp_improved(char **str, char **tab);
t_misc			ft_findcoord(char **tab, t_misc s, t_tetri tetrimino);
void			ft_erase(char **tab, t_tetri tetrimino);

int				ft_sqrt_improved(int nb);
int				size_square(int nbr_tetriminos,
		int highest_size, int longest_size);
char			**ft_tab(int n);
char			**malloc_copy_tab(int n, char **str);
t_misc			find_next_point(t_misc s, char **tab);
int				test_position(t_tetri tetriminos, t_misc s, char **tab);
char			**draw_tetriminos(t_tetri tetriminos, t_misc s, char **tab);
char			**ft_strcpy_improved(char **dest, char **tab, t_misc s);
t_misc			ft_find_spot(t_tetri tetriminos, char **tab, t_misc s);
t_misc			ft_double_test(char **tab, t_misc s, t_tetri *tetriminos);
char			**combination_recursive(t_tetri *tetriminos,
		t_misc s, char **str);
char			**resolve_recursive(t_misc s, t_tetri *tetriminos);
void			ft_putstr_improved(char **pdt, int n);

#endif
