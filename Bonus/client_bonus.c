/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 06:59:03 by kelmounj          #+#    #+#             */
/*   Updated: 2024/04/27 08:10:16 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	handler(int sig)
{
	if (sig == SIGUSR1)
		write(1, "Message received perfectly\n", 27);
}

static void	send_char(char c, int pid, int j, unsigned char res)
{
	int		tab[8];
	int		k;

	j = 0;
	res = c;
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
			kill(pid, SIGUSR1);
		else if (tab[k] == 1)
			kill(pid, SIGUSR2);
		usleep(300);
		k++;
	}
}

static void	sendsignal(char **av, int i, int j)
{
	unsigned char	res;

	signal(SIGUSR1, handler);
	res = 0;
	while (av[2][i])
	{
		send_char(av[2][i], atoi(av[1]), j, res);
		i++;
	}
	j = 0;
	res = 0;
	send_char(av[2][i], atoi(av[1]), j, res);
	i++;
}

int	main(int ac, char **av)
{
	int		i;
	int		j;

	client_parser(ac, av);
	i = 0;
	j = 0;
	sendsignal(av, i, j);
}
