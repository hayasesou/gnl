/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:39:35 by hfukushi          #+#    #+#             */
/*   Updated: 2023/07/16 18:56:02 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

size_t	ft_strlen(char *s)
{
	size_t	count;

	count = 0;
	if (s == NULL)
		return (0);
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s2 == NULL)
		return (NULL);
	s = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (s == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len + s2_len)
	{
		if (i < s1_len)
			s[i] = s1[i];
		else
			s[i] = s2[i - s1_len];
		i++;
	}
	s[i] = '\0';
	free(s1);
	return (s);
}

size_t	ft_strlcpy(char *dst, char *src, size_t destsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (destsize == 0)
		return (src_len);
	while (i < destsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char	*ft_strchr(char *s, int c)
{
	char	*s_p;
	char	letter;

	if (s == NULL)
		return (NULL);
	letter = c;
	s_p = (char *)s;
	while (*s_p != '\0' && *s_p != letter)
		s_p++;
	if (*s_p == letter)
		return (s_p);
	return (NULL);
}
