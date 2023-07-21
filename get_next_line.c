/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:02:50 by hfukushi          #+#    #+#             */
/*   Updated: 2023/07/21 15:25:07 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (save[len] == '\n')
		len += 2;
	else
		len += 1;
	line = (char *)malloc(sizeof(char) * (len));
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, save, len);
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
	if (save[len] == '\0')
	{
		free(save);
		return (NULL);
	}	
	reset = (char *)malloc(sizeof(char) * (ft_strlen(save) - len + 1));
	if (reset == NULL)
	{
		free(save);
		return (NULL);
	}
	ft_strlcpy(reset, &save[len + 1], ft_strlen(save) - len);
	free(save);
	return (reset);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	save = link_buf(fd, save);
	line = make_line(save);
	save = reset_save(save);
	return (line);
}

//static変数は最初に初期化される

// #include <fcntl.h>
// #include <stdio.h>

// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q a.out");
// }

// void test(char *s)
// {
// 	char *p;
// 	int		fd;

// 	int i;
// 	fd = open(s,O_RDONLY);
// 	i = 0;
// 	while (1)
// 	{
// 		i++;
// 		p = get_next_line(fd);
// 		printf("%d,%s\n",i, p);
// 		free(p);
// 		if(p == NULL)
// 			break ;
// 	}
// 	printf("\n=========\n");
// }
// int main()
// {
// 	test("sample.txt");
// 	test("nnewline.txt");
// 	test("lnnewline.txt");
// 	test("lnewline.txt");
// 	test("null.txt");
// 	test("mline.txt");
// 	return (0);
// }