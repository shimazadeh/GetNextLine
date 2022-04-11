/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:59:24 by shabibol          #+#    #+#             */
/*   Updated: 2022/04/11 18:51:17 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strlen(char *s1)
{
	int	i;

	i = 0;
	while (s1 && s1[i] != '\0')
		i++;
	return (i);
}

char	*ft_strndup(char *src, int size)
{
	int		i;
	char	*dest;

	i = 0;
	if (!src)
		return (0);
	dest = (char *)malloc(sizeof(char) * size + 1);
	if (!dest)
		return (0);
	while (src[i] && i != size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	j = 0;
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!dst)
		return (0);
	while (s1 && s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
		dst[i++] = s2[j++];
	dst[i] = '\0';
	return (dst);
}

int	ft_strchr(char *s1)
{
	if (!s1 || s1 == NULL)
		return (0);
	while (*s1 && *s1 != '\n')
		s1++;
	if (*s1 == '\n')
		return (1);
	return (0);
}

char	*ft_strfind(char *s1, char set)
{
	int		i;
	char	*dest;

	i = 0;
	if (!s1 || !set)
		return (0);
	while (s1 && s1[i] != set)
		i++;
	if (s1[i] == set)
	{
		dest = ft_strndup(s1, i + 1);
		free(s1);
		return (dest);
	}
	return (0);
}
