/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:02:50 by hfukushi          #+#    #+#             */
/*   Updated: 2023/07/16 18:00:00 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *link_buf(int fd, char *save, int *readcount)
{
	long	bytes;
	char *	buf;
(void )fd;
	buf = (char *)malloc((sizeof(char)* (BUFFER_SIZE + 1)));
	if (!buf)
		return (NULL);
	bytes = 1;
	while (bytes != 0 && (!ft_strchr(save, '\n')))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buf);
			free (save);
			return (NULL);
		}
		if (bytes == 0)
		{
			free(buf);
			if (ft_strlen (save) != 0)
				return (save);
			free(save);
			return (NULL);
		}
		buf[bytes] = '\0';
		save = ft_strjoin(save, buf);
	}
	free(buf);
	*readcount = bytes;
	return (save);
}

char	*make_line(char *save)
{
	size_t	len;
	char	*line;

	len = 0;
	if (save == NULL)
		return (NULL);
	while (save[len] != '\0' && save[len] != '\n')
		len++;
	line = (char *)malloc(sizeof(char ) * (len + 2));
	if (line == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(line, save, len + 2);
	return (line);
}

char	*reset_save(char *save)
{
	size_t	len;
	char	*reset;

	len = 0;
	if ( save == NULL)
		return (NULL);
	while (save[len] != '\0' && save[len] != '\n')
		len++;
	reset = (char *)malloc(sizeof(char) * (ft_strlen(save) - len +1 ));//changed
	if ( reset == NULL)
	{
		free(save);
		return (NULL);
	}
	if ( save[len] == '\0')
	{
		free(save);
		free(reset);
		return (NULL);
	}
	ft_strlcpy(reset, &save[len + 1], ft_strlen(save) - len);
	free(save);
	return (reset);
}

char *get_next_line(int fd)
{
	static char	*save;
	char		*line;
	int			readcount;

	readcount = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	save = link_buf(fd, save, &readcount);
	line = make_line(save);
	save = reset_save(save);
	return (line);
}



// char *link_buf(int fd, char *save)
// {
// 	char	*buf;
// 	long	bytes;
	
// 	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (buf == NULL)
// 		return (NULL);
// 	while(1)
// 	{
// 		bytes = read(fd, buf, BUFFER_SIZE);
// 		if (bytes == -1)
// 		{
// 			free(save);
// 			free(buf);
// 			return(NULL);
// 		}
// 		if (bytes == 0)
// 		{
// 			free(save);
// 			break ;
// 		}
// 		buf[bytes] = '\0';
// 		save = ft_strjoin(save, buf);
// 		if(ft_strchr(save ,'\n') != NULL)
// 			break ;
// 	}
// }


//static変数は最初に初期化される


#include <fcntl.h>

// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q a.out");
// }

// int main()
// {
// 	char *p;
// 	int	 fd;

// 	int i;
// 	fd = open("sample.txt",O_RDONLY); 
// 	i = 0;
// 	while (1)
// 	{
// 		i++;
// 		// printf("\n\n===== %d ====\n", i);
// 		p = get_next_line(fd);
// 		printf("%d,%s\n",i, p);
// 		free(p);
// 		if(p == NULL)
// 			break ;
// 	}
// 	return (0);
// }