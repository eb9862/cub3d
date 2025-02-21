/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:33:45 by eunhwang          #+#    #+#             */
/*   Updated: 2024/06/11 17:14:32 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 24
# endif

# include <stddef.h>

char	*get_next_line(int fd);
char	*gnl_strjoin(char const *s1, char const *s2);
size_t	gnl_strlen(const char *s);
size_t	gnl_strlcpy(char *dst, const char *src, size_t size);

#endif
