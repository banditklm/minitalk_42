/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 00:05:14 by kelmounj          #+#    #+#             */
/*   Updated: 2024/04/27 11:58:28 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <libc.h>

char	*ft_itoa(int n);
void	ft_putstr(char *s);
size_t	ft_strlen(char *s);
char	*ft_strtrim(char *s1, char *set);
void	client_parser(int ac, char **av);
int		ft_atoi(char *str);
int		is_num(char *s);

#endif