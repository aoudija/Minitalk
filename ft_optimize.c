/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:16:13 by aoudija           #+#    #+#             */
/*   Updated: 2022/12/30 15:22:38 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_optimize(va_list args, char c)
{
	int	j;

	j = 0;
	if (c == 'i' || c == 'd')
		j = ft_putnbr(va_arg(args, int));
	else if (c == 'c')
		j = ft_putchar(va_arg(args, int));
	else if (c == 's')
		j = ft_putstr(va_arg(args, char *));
	else if (c == '%')
		j = ft_putchar('%');
	else
		j = ft_putchar(c);
	return (j);
}
