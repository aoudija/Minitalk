/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:52:48 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/09 11:13:48 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>

size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memset(void *str, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
void	ft_putnbr_fd(int n);
void	ft_putstr_fd(char *s);
void	ft_putchar_fd(char c);
void	*ft_calloc(size_t count, size_t size);
void	ft_free(char **table);
void	ft_optimize(char *g);
char	*decimal_to_msg(int *table);
int		*binary_to_decimal(char *bn);

#endif