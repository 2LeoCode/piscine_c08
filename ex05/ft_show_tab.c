/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:07:30 by lsuardi           #+#    #+#             */
/*   Updated: 2020/02/20 21:22:02 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnum(long i)
{
	char a;

	a = (char)i;
	write(1, &a, 1);
}

void	ft_putnbr(int nbr)
{
	long i;

	i = (long)nbr;
	if (i < 0)
	{
		write(1, "-", 1);
		i *= -1;
	}
	if (i > 9)
	{
		ft_putnbr((int)(i / 10));
		ft_putnbr((int)(i % 10));
	}
	else
		ft_putnum(i + 48);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;
	int j;

	i = 0;
	while (par[i].str)
	{
		j = -1;
		while (par[i].str[++j])
			write(1, &par[i].str[j], 1);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		j = -1;
		while (par[i].copy[++j])
			write(1, &par[i].str[j], 1);
		write(1, "\n", 1);
		i++;
	}
}
