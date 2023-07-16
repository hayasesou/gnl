/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:02:44 by hfukushi          #+#    #+#             */
/*   Updated: 2023/07/16 17:59:16 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(char *s)
{
	size_t	count;

	count = 0;
	if ( s == NULL)
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
	size_t  s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s2 == NULL)
		return (NULL);
	s = (char *)malloc(sizeof(char)*(s1_len + s2_len + 1));
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

#include <stdio.h>

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
		return NULL;
	letter = c;
	s_p = (char *)s;
	while (*s_p != '\0' && *s_p != letter)
		s_p++;
	if (*s_p == letter)
		return (s_p);
	return (NULL);
}

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	char	*str;

// 	if (s == NULL)
// 		return (NULL);
// 	i = 0;
// 	if (ft_strlen(s) - start < len)
// 		len = ft_strlen(s) - start;
// 	if (ft_strlen(s) < start)
// 		len = 0;
// 	str = (char *)malloc(sizeof(char) * len + 1);
// 	if (str == NULL)
// 		return (NULL);
// 	if (start < ft_strlen(s))
// 	{
// 		while (s[i + start] != '\0' && i < len)
// 		{	
// 			str[i] == s[i + start];
// 			i++;
// 		}
// 	}
// 	str[i] = '\0';
// 	return (str);
// }