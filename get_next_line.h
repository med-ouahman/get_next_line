/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:18:06 by mouahman          #+#    #+#             */
/*   Updated: 2024/11/14 09:46:01 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*ft_strchr(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
char	*ft_substr(char *str, size_t index);
char	*get_next_line(int fd);

#endif