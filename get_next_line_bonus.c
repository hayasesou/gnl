/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:38:39 by hfukushi          #+#    #+#             */
/*   Updated: 2023/07/21 15:25:54 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*link_buf(int fd, char *save)
{
	long	bytes;
	char	*buf;

	buf = (char *)malloc((sizeof(char) * (BUFFER_SIZE + 1)));
	if (!buf)
		return (NULL);
	bytes = 1;
	while (bytes != 0 && (!ft_strchr(save, '\n')))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == 0 || bytes == -1)
		{
			free(buf);
			if (bytes == 0 && ft_strlen(save) != 0)
				return (save);
			free(save);
			return (NULL);
		}
		buf[bytes] = '\0';
		save = ft_strjoin(save, buf);
	}
	free(buf);
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
	line = (char *)malloc(sizeof(char) * (len + 2));
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
	if (save == NULL)
		return (NULL);
	while (save[len] != '\0' && save[len] != '\n')
		len++;
	reset = (char *)malloc(sizeof(char) * (ft_strlen(save) - len + 1));
	if (reset == NULL)
	{
		free(save);
		return (NULL);
	}
	if (save[len] == '\0')
	{
		free(save);
		free(reset);
		return (NULL);
	}
	ft_strlcpy(reset, &save[len + 1], ft_strlen(save) - len);
	free(save);
	return (reset);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	save[fd] = link_buf(fd, save[fd]);
	line = make_line(save[fd]);
	save[fd] = reset_save(save[fd]);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>
// #include <stdarg.h>

// void test(char *s1, char *s2, char *s3)
// {
// 	char *p;
// 	int		fd1, fd2, fd3;

// 	int i;
// 	fd1 = open(s1,O_RDONLY);
// 	fd2 = open(s2,O_RDONLY);
// 	fd3 = open(s3,O_RDONLY);
// 	i = 0;
// 	while (1)
// 	{
// 		i++;
// 		printf("\n====== %d =======\n",i);
// 		p = get_next_line(fd1);
// 		printf("fd = [%d],%s\n\n",fd1, p);
// 		p = get_next_line(fd2);
// 		printf("fd = [%d],%s\n\n",fd2, p);
// 		p = get_next_line(fd3);
// 		printf("fd = [%d],%s\n\n",fd3, p);
// 		free(p);
// 		if(i > 2 )
// 			break ;
// 	}
// 	printf("\n==========================================\n");
// }
// int main()
// {
// 	test("sample.txt","nnewline.txt","lnnewline.txt");
// 	test("lnewline.txt","null.txt","mline.txt");
// 	return (0);
// }