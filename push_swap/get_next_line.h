/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaoui <salaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:32:25 by salaoui           #+#    #+#             */
/*   Updated: 2024/06/09 13:45:51 by salaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*gnl_shrink_buffer(char *buf, char *line);
char	*gnl_expand_buffer(char *buf, int fd);
char	*gnl_newread(int fd);
int		ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

#endif