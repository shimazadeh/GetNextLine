/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 22:11:06 by shabibol          #+#    #+#             */
/*   Updated: 2022/04/11 17:44:39 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

int	ft_strlen(char *s1);

char	*ft_strndup(char *src, int size);
char	*ft_strjoin(char *s1, char *s2);
int     ft_strchr(char *s1);
char	*ft_strfind(char *s1, char set);
char	*get_next_line(int fd);
void	ft_update_buffer(char *buffer, int size);
void    ft_update_line(char *line, int size);
#endif
