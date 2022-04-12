/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:55:11 by shabibol          #+#    #+#             */
/*   Updated: 2022/04/11 18:51:15 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	ft_update_buffer(char *buffer, int size)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
/*	if (!buffer)
	{
			buffer == NULL;
			return ;
	}*/
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
	while (j < size)
	{
		buffer[j] = '\0';
		j++;
	}
}
void	ft_update_line(char *line, int size)
{
	int	i;

	i = 0;
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
	static char		*tosave;
	char			buffer[BUFFER_SIZE + 1];
	char			*line;
	int				byte_read;
	char			*temp;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	line = ft_strndup(tosave, ft_strlen(tosave));
	free(tosave);
	byte_read = 1;
	buffer[0] = 0;
	while (byte_read && !ft_strchr(buffer))
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == 0)
			return (line);
		if (byte_read < 0)
			return (NULL);
		buffer[byte_read] = '\0';
		temp = ft_strjoin(line, buffer);
		free(line);
		line = temp;
	}
	ft_update_line(line, ft_strlen(line));
//	line = ft_strfind(line, '\n');
	ft_update_buffer(buffer, BUFFER_SIZE);
	tosave = ft_strndup(buffer, BUFFER_SIZE);
	return (line);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*res;

	(void)ac;
	(void)av;
	fd = open("41_with_nl", O_RDONLY);
	if (fd == -1)
		printf("Error with reading the file\n");
	else
		printf("fd is : %d\n", fd);
	while ((res = get_next_line(fd)))
	{
		printf("%s", res);
		free(res);
	}
	printf("%s", res);
	close(fd);
	return (0);
}