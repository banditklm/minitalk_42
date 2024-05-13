/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 00:02:14 by kelmounj          #+#    #+#             */
/*   Updated: 2024/04/27 14:23:24 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	sig_handler(int n, struct __siginfo *info, void *p)
{
	static int		tab[8];
	static pid_t	pid;
	static int		i;
	int				j;
	int				res;

	p = NULL;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		i = 0;
	}
	if (n == 30)
		tab[i] = 0;
	else if (n == 31)
		tab[i] = 1;
	i++;
	if (i == 8)
	{
		(1) && (res = 0, j = 8);
		while (--j >= 0)
			res = (res * 2) + tab[j];
		write(1, &res, 1);
		i = 0;
	}
}

int	main(void)
{
	char				*pid;
	struct sigaction	act;

	pid = ft_itoa(getpid());
	if (!pid)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	ft_putstr(pid);
	free(pid);
	write(1, "\n", 1);
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	act.sa_sigaction = sig_handler;
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
	{
		pause();
	}
}
