/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:34:36 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/04 20:39:55 by aoudija          ###   ########.fr       */
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
