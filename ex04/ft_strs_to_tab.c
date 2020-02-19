/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 00:02:19 by lsuardi           #+#    #+#             */
/*   Updated: 2020/02/19 21:59:04 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stock_str.h"
#include <stdlib.h>

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void				ft_strcpy(char *src, char *dest)
{
	int i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = 0;
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int i;

	struct s_stock_str *lol;
	lol = 0;
	if (malloc(sizeof(struct s_stock_str) * ac + 1 ) == NULL)
		return (lol);
	lol = malloc(sizeof(struct s_stock_str) * ac + 1);
	i = 0;
	while (i < ac - 1)
	{
		lol[i].size = ft_strlen(av[i + 1]);
		lol[i].str = av[i + 1];
		if ((char*)malloc(sizeof(char) * lol[i].size + 1) == NULL)
		{
			lol = 0;
			return (lol);
		}
		lol[i].copy = (char*)malloc(sizeof(char) * lol[i].size + 1);
		ft_strcpy(lol[i].str, lol[i].copy);
		i++;
	}
	lol[i].str = 0;
	return(lol);
}
