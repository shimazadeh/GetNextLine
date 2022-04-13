/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:36:04 by shabibol          #+#    #+#             */
/*   Updated: 2022/04/13 23:55:23 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_update_buffer(char *buffer, int size)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
	{
		buffer[j] = buffer[++i];
		j++;
		i++;
	}
	while (i < size && buffer[j])
	{
		buffer[j] = buffer[i];
		i++;
		j++;
	}
	while (j < size && buffer[j])
	{
		buffer[j] = '\0';
		j++;
	}
}

void	ft_update_line(char *line, int size)
{
	int	i;

	i = 0;
	if (!line)
		return ;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	while (i < size && line[i])
	{
		line[i] = '\0';
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char			buffer[1024][BUFFER_SIZE + 1];
	char				*line;
	int					byte_read;
	char				*temp;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	line = ft_strndup(buffer[fd], ft_strlen(buffer[fd]));
	byte_read = 1;
	while (byte_read && !ft_gnl_strchr(buffer[fd]) && !ft_gnl_strchr(line))
	{
		byte_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (byte_read < 0)
			return (NULL);
		if (byte_read == 0 && !line)
			return (NULL);
		buffer[fd][byte_read] = '\0';
		temp = ft_strjoin(line, buffer[fd]);
		free(line);
		line = temp;
	}
	ft_update_buffer(buffer[fd], BUFFER_SIZE);
	ft_update_line(line, ft_strlen(line));
	return (line);
}
/*
int	main(int ac, char **av)
{
	int		fd1;
	int		fd2;
	char	*res1;
	char	*res2;

	fd1 = open("41_no_nl", O_RDONLY);
	fd2 = open("41_with_nl", O_RDONLY);
	if (fd1 == -1 || fd2 == -1)
		printf("Error with reading the file\n");
	else
		printf("fd1 is: %d and fd2 is: %d\n", fd1, fd2);
	while ((res1 = get_next_line(fd1)) || (res2 = get_next_line(fd2)))
	{
		printf("%s", res1);
		printf("%s", res2);
		free(res1);
		free(res2);
	}
	printf("%s", res1);
	printf("%s", res2);
	close(fd1);
	close(fd2);
	return (0);
}*/
