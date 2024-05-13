/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 00:02:17 by kelmounj          #+#    #+#             */
/*   Updated: 2024/04/27 11:57:31 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	sendsignal(char **av, int i, int j, int k)
{
	int				tab[8];
	unsigned char	res;

	while (av[2][i])
	{
		j = 0;
		res = av[2][i];
		while (j <= 7)
		{
			tab[j] = res % 2;
			res = res / 2;
			j++;
		}
		k = 0;
		while (k <= 7)
		{
			if (tab[k] == 0)
				kill(atoi(av[1]), SIGUSR1);
			else if (tab[k] == 1)
				kill(atoi(av[1]), SIGUSR2);
			usleep(100);
			k++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	int		k;

	client_parser(ac, av);
	i = 0;
	j = 0;
	k = 0;
	sendsignal(av, i, j, k);
}
