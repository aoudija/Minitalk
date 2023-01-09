/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:34:36 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/08 18:59:01 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	int		i;

	i = count * size;
	p = malloc(i);
	if (!p)
		return (NULL);
	while (i--)
		p[i] = 0;
	return (p);
}

void	ft_putchar_fd(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_fd(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i]);
		i++;
	}
}

void	ft_putnbr_fd(int n)
{
	char	*s;

	s = ft_itoa(n);
	ft_putstr_fd(s);
	free(s);
}
