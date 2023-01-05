/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:52:22 by aoudija           #+#    #+#             */
/*   Updated: 2022/12/30 13:23:25 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_putstr(char *s)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (!s)
		j += ft_putstr("(null)");
	else
	{
		while (s[i])
		{
			j += ft_putchar(s[i]);
			i++;
		}
	}
	return (j);
}
