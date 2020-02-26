/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 00:02:19 by lsuardi           #+#    #+#             */
/*   Updated: 2020/02/26 17:48:58 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strdup(char *src)
{
	char	*tab;
	int		i;

	i = 0;
	if (!tab = malloc(ft_strlen(src) + 1))
		return (NULL);
	while (src[i])
	{
		tab[i] = src[i];
		i++;
	}
	tab[i] = 0;
	return (tab)
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*lol;

	lol = 0;
	if (malloc(sizeof(struct s_stock_str) * ac + 1) == NULL)
		return (NULL);
	lol = malloc(sizeof(struct s_stock_str) * ac + 1);
	i = 0;
	while (i < ac - 1)
	{
		lol[i].size = ft_strlen(av[i]);
		lol[i].str = av[i];
		if ((char*)malloc(sizeof(char) * lol[i].size + 1) == NULL)
		{
			lol = 0;
			return (NULL);
		}
		lol[i].copy = ft_strdup(av[i]);
		i++;
	}
	lol[i].str = 0;
	return (lol);
}
