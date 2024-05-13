/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 06:59:16 by kelmounj          #+#    #+#             */
/*   Updated: 2024/04/27 14:24:03 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	restart_byte(pid_t *pid, pid_t new_pid, int *i)
{
	if (*pid != new_pid)
		(1) && (*pid = new_pid, *i = 0);
}

static void	handle_unicode(int tab[], int *i, pid_t pid)
{
	one_byte(tab, &i, pid);
	two_byte(tab, &i);
	three_byte(tab, &i);
	four_byte(tab, &i);
}

void	sig_handler(int n, struct __siginfo *info, void *p)
{
	static int		tab[32] = {0};
	static pid_t	pid;
	static int		i;

	p = NULL;
	restart_byte(&pid, info->si_pid, &i);
	if (n == 30)
		tab[i] = 0;
	else if (n == 31)
		tab[i] = 1;
	i++;
	handle_unicode(tab, &i, pid);
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
