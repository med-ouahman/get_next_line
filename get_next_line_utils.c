/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:22:22 by mouahman          #+#    #+#             */
/*   Updated: 2024/11/12 10:49:41 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*dup;
	size_t	len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	dup = malloc(len * sizeof(char) + 1);
	if (!dup)
		return (dup);
	len = 0;
	while (str[len])
	{
		dup[len] = str[len];
		len++;
	}
	dup[len] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	i;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	joined = malloc(len * sizeof(char) + 1);
	if (!joined)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	len = 0;
	while (s2[len])
	{
		joined[i + len] = s2[len];
		len++;
	}
	joined[i + len] = '\0';
	return (joined);
}

char	*ft_substr(char *str, size_t index)
{
	char	*sub;
	size_t	len;
	size_t	i;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (index >= len)
		return (ft_strdup(""));
	sub = malloc((len - index) * sizeof(char) + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (str[i + index])
	{
		sub[i] = str[i + index];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strchr(char *str, char c)
{
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (NULL);
}
