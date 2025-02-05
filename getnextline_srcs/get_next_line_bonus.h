/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:40:23 by pdessant          #+#    #+#             */
/*   Updated: 2025/01/17 11:33:12 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"
# include "fcntl.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct n_struct
{
	char	*buffer;
	char	*newline_pos;
	char	*line;
	int		bytes;
}	t_s;

int		ft_strlen(const char *str);
int		len_keeper(char *keeper);
int		back_slash_n(char *s);

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*dup_after_n(char *keeper);
char	*sdup_to_n(char *s);
char	*get_next_line(int fd);

void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_calloc(size_t nmemb, size_t size);
void	free_alloc(char **s);
void	buff_alloc(char **buff);

#endif
