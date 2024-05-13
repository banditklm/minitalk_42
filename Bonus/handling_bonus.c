/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 08:12:18 by kelmounj          #+#    #+#             */
/*   Updated: 2024/04/27 08:47:40 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	check_if_unicod(int tab[])
{
	int	i;
	int	res;

	res = 0;
	i = 7;
	while (tab[i])
	{
		i--;
		res++;
	}
	return (res);
}

void	one_byte(int tab[], int **i, pid_t pid)
{
	int	j;
	int	res;

	if (**i == 8 && (check_if_unicod(tab) == 0 || check_if_unicod(tab) == 1))
	{
		(1) && (res = 0, j = 8);
		while (--j >= 0)
			res = (res * 2) + tab[j];
		if (res == 0)
			kill(pid, SIGUSR1);
		write(1, &res, 1);
		**i = 0;
	}
}

void	two_byte(int tab[], int **i)
{
	int	j;
	int	res;

	if (**i == 16 && check_if_unicod(tab) == 2)
	{
		(1) && (res = 0, j = 8);
		while (--j >= 0)
			res = (res * 2) + tab[j];
		write(1, &res, 1);
		(1) && (res = 0, j = 16);
		while (--j >= 8)
			res = (res * 2) + tab[j];
		write(1, &res, 1);
		**i = 0;
	}
}

void	three_byte(int tab[], int **i)
{
	int	j;
	int	res;

	if (**i == 24 && check_if_unicod(tab) == 3)
	{
		(1) && (res = 0, j = 8);
		while (--j >= 0)
			res = (res * 2) + tab[j];
		write(1, &res, 1);
		(1) && (res = 0, j = 16);
		while (--j >= 8)
			res = (res * 2) + tab[j];
		write(1, &res, 1);
		(1) && (res = 0, j = 24);
		while (--j >= 16)
			res = (res * 2) + tab[j];
		write(1, &res, 1);
		**i = 0;
	}
}

void	four_byte(int tab[], int **i)
{
	int	j;
	int	res;

	if (**i == 32 && check_if_unicod(tab) == 4)
	{
		(1) && (res = 0, j = 8);
		while (--j >= 0)
			res = (res * 2) + tab[j];
		write(1, &res, 1);
		(1) && (res = 0, j = 16);
		while (--j >= 8)
			res = (res * 2) + tab[j];
		write(1, &res, 1);
		(1) && (res = 0, j = 24);
		while (--j >= 16)
			res = (res * 2) + tab[j];
		write(1, &res, 1);
		(1) && (res = 0, j = 32);
		while (--j >= 24)
			res = (res * 2) + tab[j];
		write(1, &res, 1);
		**i = 0;
	}
}
