/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:55:11 by shabibol          #+#    #+#             */
/*   Updated: 2022/04/06 19:24:44 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int	ft_strlen(char *s1)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	return (i);
}

char	*ft_strlcpy(char *src, int size)
{
	int		i;
	char	*dest;
	i= 0;
	dest = (char *)malloc(sizeof(char) * size);
	if (!src || !dest)
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
	if (s1 == NULL || s2 == NULL)
		return (0);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!dst)
		return (0);
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		dst[i++] = s2[j++];
	dst[i] = '\0';
	return (dst);
}

char	*ft_strchr(char *s1)
{
	if (!s1)
		return (0);
	while (*s1 && *s1 != '\n')
		s1++;
	if (*s1 == '\n')
		return (s1);
	return (0);
}

char	*ft_strfind(char *s1, char set)
{
	int		i;
	char	*dest;
	i = 0;
	if (!s1 || !set)
		return (0);
	while (s1[i] && s1[i] != set)
		i++;
	if (s1[i] == set)
	{
		dest = ft_strlcpy(s1, i);
		free(s1);
		return (dest);
	}
	else
		return (0);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*res;
	int			byte_read;
//	int			BUFFER_SIZE;

	if (!fd)
		return (0);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	byte_read = read(fd, buffer, BUFFER_SIZE);
	line = ft_strlcpy(buffer, BUFFER_SIZE);
	while (line && ft_strchr(line) == 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		res = ft_strjoin(line, buffer);

	}
	if (ft_strchr(line) != 0)
		output = ft_strfind(line, '\n');
	free(buffer);
	return (line);
}

int	main(int ac, char **av)
{
	int fd;
	(void)ac;
	(void)av;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		printf("Error with reading the file\n");
	else
		printf("fd is : %d\n", fd);
	printf("the line is: %s\n", get_next_line(fd));
	close(fd);
	return (0);

}
