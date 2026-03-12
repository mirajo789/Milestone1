/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirajora <mirajora@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:41:04 by mirajora          #+#    #+#             */
/*   Updated: 2026/02/26 11:38:59 by mirajora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

size_t	ft_strlen(char	*s);
char	*ft_strjoin(char	*s1, char	*s2);
char	*ft_strdup(char *src);
char	*ft_substr(char	*s, unsigned int start, size_t len);
char	*ft_strchr(char *s, int c);
char	*get_next_line(int fd);
#endif
