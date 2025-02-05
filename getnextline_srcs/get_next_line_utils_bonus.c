/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:51:06 by pdessant          #+#    #+#             */
/*   Updated: 2025/01/17 11:33:39 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line_bonus.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*c;
	size_t	s;
	size_t	i;

	s = nmemb * size;
	if (nmemb != 0 && s / nmemb != size)
		return (NULL);
	c = (void *)malloc(s);
	if (!c)
		return (NULL);
	i = 0;
	while (i < s)
	{
		((char *)c)[i] = '\0';
		i++;
	}
	return (c);
}

void	free_alloc(char **s)
{
	if (*s)
	{
		free(*s);
		*s = 0;
	}
}

char	*ft_strchr(const char *s, int c)
{
	char	p;
	int		a;

	if (s == NULL)
		return (NULL);
	a = 0;
	p = (unsigned char)c;
	while (s[a])
	{
		if (s[a] == p)
			return ((char *)&s[a]);
		a++;
	}
	if (p == '\0')
		return ((char *)&s[a]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*a;
	size_t	i;
	size_t	x;
	size_t	len;

	i = -1;
	x = -1;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	a = (char *)malloc(sizeof(char) * (len + 1));
	if (!a)
		return (NULL);
	while (s1 != NULL && s1[++i])
		a[i] = s1[i];
	while (s2[++x])
		a[i + x] = s2[x];
	a[i + x] = '\0';
	free(s1);
	return (a);
}
