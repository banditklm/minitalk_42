/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 00:05:16 by kelmounj          #+#    #+#             */
/*   Updated: 2024/04/27 11:58:49 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <libc.h>

int		ft_atoi(char *str);
char	*ft_itoa(int n);
void	ft_putstr(char *s);
size_t	ft_strlen(char *s);
char	*ft_strtrim(char *s1, char *set);

#endif