/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:33:16 by mouahman          #+#    #+#             */
/*   Updated: 2024/11/15 08:36:32 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*copy_line(char *stock)
{
	char	*line;
	size_t	i;

	if (!stock)
		return (NULL);
	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (stock[i] == '\n')
		i++;
	line = malloc(i * sizeof(char) + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stock[i] && stock[i] != '\n')
	{
		line[i] = stock[i];
		i++;
	}
	if (stock[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*set_stock(char *stock)
{
	char	*rest;
	size_t	i;

	if (!stock)
		return (NULL);
	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	rest = ft_substr(stock, i + 1);
	if (!rest)
		return (NULL);
	if (!(*rest))
	{
		free(rest);
		return (NULL);
	}
	return (rest);
}

static char	*get_stock(int fd, char *stock)
{
	ssize_t	bytes;
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp;

	buffer[0] = '\0';
	while (!ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (NULL);
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		if (!stock)
			stock = ft_strdup(buffer);
		else
		{
			tmp = stock;
			stock = ft_strjoin(tmp, buffer);
			free(tmp);
		}
	}
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	*stocks[MAX_FILES + 1] = {NULL};
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FILES)
		return (NULL);
	stocks[fd] = get_stock(fd, stocks[fd]);
	if (!stocks[fd])
		return (NULL);
	line = copy_line(stocks[fd]);
	if (!line)
		return (NULL);
	tmp = stocks[fd];
	stocks[fd] = set_stock(tmp);
	free(tmp);
	if (!(*line) && !stocks[fd])
	{
		free(line);
		return (NULL);
	}
	return (line);
}
