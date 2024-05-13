/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 00:27:07 by kelmounj          #+#    #+#             */
/*   Updated: 2024/04/27 15:17:22 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

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
			free(str);
			return (0);
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
