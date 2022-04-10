/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 22:11:06 by shabibol          #+#    #+#             */
/*   Updated: 2022/04/10 22:11:08 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

int	ft_strlen(char *s1);

char	*ft_strndup(char *src, int size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s1);
char	*ft_strfind(char *s1, char set);

void	ft_update_buffer(char *buffer, int size);

#endif
