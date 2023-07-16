/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:03:04 by hfukushi          #+#    #+#             */
/*   Updated: 2023/07/16 13:31:17 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

# define OPEN_MAX 10240 

# include <unistd.h>
# include <stdlib.h>
// # include <syslimits.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*ft_strchr(char  *s, int c);
size_t	ft_strlcpy(char *dst, char *src, size_t destsize);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif