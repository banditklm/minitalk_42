/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 00:38:26 by kelmounj          #+#    #+#             */
/*   Updated: 2024/04/27 13:57:04 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*ft_strdup(char *s1)
{
	int		len;
	int		i;
	char	*s2;

	len = 0;
	i = 0;
	while (s1[len])
	{
		len++;
	}
	s2 = (char *)malloc((len * 1) + 1);
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int	ft_memcmp(void *s1, void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n < 1)
	{
		return (0);
	}
	while (i < n
		&& (*(unsigned char *)(s1 + i)) == (*(unsigned char *)(s2 + i)))
	{
		i++;
	}
	if (i == n)
		return (0);
	return ((*(unsigned char *)(s1 + i)) - (*(unsigned char *)(s2 + i)));
}

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t	i;

	if (dst == (void *)0 && src == (void *)0)
		return (dst);
	if (ft_memcmp(dst, src, n) == 0)
		return (dst);
	i = 0;
	while (i < n)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		i++;
	}
	return (dst);
}

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	*ptr;
	int		len;

	len = 0;
	len = ft_strlen(s);
	ptr = (char *)s;
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
		{
			return (ptr + i);
		}
		i++;
	}
	if ((unsigned char)c == 0)
		return (ptr + i);
	return (NULL);
}

char	*ft_strtrim(char *s1, char *set)
{
	int		i;
	int		len;
	char	*str;
	int		size;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	len = ft_strlen(s1);
	if (i > len - 1)
		return (ft_strdup(""));
	while (len > 0 && ft_strchr(set, s1[len]))
		len--;
	size = len - i + 1;
	str = (char *)malloc(size * sizeof(char) + 1);
	if (!str)
		return (NULL);
	str = ft_memcpy(str, (s1 + i), size);
	str[size] = '\0';
	return (str);
}
