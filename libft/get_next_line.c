/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 15:14:12 by cshawnee          #+#    #+#             */
/*   Updated: 2020/01/17 18:14:24 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"

static int	linecheck(char **arr, char **line)
{
	char	*temp;
	char	*temp2;
	int		i;

	i = 0;
	temp2 = *arr;
	while (temp2[i] != '\n')
		if (!temp2[i++])
			return (0);
	temp = &temp2[i];
	*temp = '\0';
	*line = ft_strdup(*arr);
	*arr = ft_strdup(temp + 1);
	free(temp2);
	temp2 = NULL;
	temp = NULL;
	return (1);
}

static int	readfile(int fd, char *buff, char **arr, char **line)
{
	int		i;
	char	*temp;

	while ((i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[i] = '\0';
		if (*arr)
		{
			temp = *arr;
			*arr = ft_strjoin(temp, buff);
			free(temp);
			temp = NULL;
		}
		else
			*arr = ft_strdup(buff);
		if (linecheck(arr, line))
			break ;
	}
	if (i > 0)
		return (1);
	else
		return (i);
}

int			get_next_line(const int fd, char **line)
{
	static char	*arr[MAX_FD];
	char		*buff;
	int			i;
	int			res;

	i = 0;
	if (!line || fd < 0 || fd > MAX_FD || (read(fd, arr[fd], 0) < 0) ||
		!(buff = (char *)malloc(sizeof(*buff) * BUFF_SIZE + 1)))
		return (-1);
	if (arr[fd])
		if (linecheck(&arr[fd], line))
			return (1);
	while (i < BUFF_SIZE)
		buff[i++] = '\0';
	res = readfile(fd, buff, &arr[fd], line);
	free(buff);
	if (res != 0 || arr[fd] == NULL || arr[fd][0] == '\0')
	{
		if (!res && *line)
			*line = NULL;
		return (res);
	}
	*line = arr[fd];
	arr[fd] = NULL;
	return (1);
}
