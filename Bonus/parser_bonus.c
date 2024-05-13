/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 06:59:14 by kelmounj          #+#    #+#             */
/*   Updated: 2024/04/27 14:43:53 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	is_num(char *s)
{
	char	*str;
	int		i;

	str = ft_strtrim(s, " ");
	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
		{
			return (0);
			free(str);
		}
		i++;
	}
	free(str);
	return (1);
}

void	client_parser(int ac, char **av)
{
	if (ac == 3)
	{
		if (!is_num(av[1]))
		{
			write (1, "Error\n", 6);
			exit(1);
		}
	}
	else
	{
		write (1, "Error\n", 6);
		exit(1);
	}
}
