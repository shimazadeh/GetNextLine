/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:37:04 by shabibol          #+#    #+#             */
/*   Updated: 2022/04/13 23:55:21 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

int		ft_strlen(char *s1);
int     ft_gnl_strchr(char *s1);

char	*ft_strndup(char *src, int size);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

void	ft_update_buffer(char *buffer, int size);
void    ft_update_line(char *line, int size);
#endif
