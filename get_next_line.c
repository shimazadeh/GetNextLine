/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:55:11 by shabibol          #+#    #+#             */
/*   Updated: 2022/04/07 15:24:35 by shabibol         ###   ########.fr       */
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

char	*ft_strndup(char *src, int size)
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

char	*ft_strchr_temp(char *s1)
{
	if (!s1)
		return (0);
	while (*s1 && *s1 != '\n')
		s1++;
	if (*s1 == '\n')
		s1++;
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
		dest = ft_strndup(s1, i + 1);
		return (dest);
	}
	else
		return (0);
}

char	*get_next_line(int fd)
{
	static char	 buffer[BUFFER_SIZE + 1];
	static char	*line;
	char	*res;
	int			byte_read;
	char		*temp;
	char		*tmp;

	if (!fd)
		return (0);
	if (buffer[0])
	{
		temp = ft_strchr(buffer);
		if (ft_strchr(temp))
			{ 
				tmp = ft_strfind(temp, '\n');
			//	free(temp);
				temp = tmp;
			}
		res = ft_strjoin(line, temp);
		free(line);
		line = res;
	}
	while ((byte_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[byte_read] = '\0';
		if (!line)
			line = ft_strndup(buffer, byte_read + 1);
		else
		{
			if (ft_strchr(buffer) == 0)
				res = ft_strjoin(line, buffer);
			else
			{
				temp = ft_strfind(buffer, '\n');
				res = ft_strjoin(line, temp);
				free(line);
				line = res;
				return (line);
			}
//			free(line);
			line = res;
		}
	}
	return (NULL);
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
	printf("the first round res is: %s\n", get_next_line(fd));
	printf("\n");
	printf("the second round res is: %s\n", get_next_line(fd));
	printf("\n");
	printf("the third round res is: %s\n", get_next_line(fd));
	printf("\n");
	printf("the fourth round res is: %s\n", get_next_line(fd));
	close(fd);
	return (0);

}
