/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 06:59:11 by kelmounj          #+#    #+#             */
/*   Updated: 2024/04/27 11:56:17 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

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
void	one_byte(int tab[], int **i, pid_t pid);
void	two_byte(int tab[], int **i);
void	three_byte(int tab[], int **i);
void	four_byte(int tab[], int **i);

#endif