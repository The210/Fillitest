/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_improved.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:41:17 by ybouzgao          #+#    #+#             */
/*   Updated: 2017/12/15 16:54:19 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp_improved(char **str, char **tab)
{
	int i;
	int f;

	f = 0;
	i = 0;
	while(str[i])
	{
		if (ft_strcmp(str[i], tab[i]) != 0)
			f = 1;
		i++;
	}
	return (f);
}
