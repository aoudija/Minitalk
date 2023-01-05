/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:41:12 by aoudija           #+#    #+#             */
/*   Updated: 2022/12/30 13:23:52 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		len;

	if (write(1, &s[0], 0) < 0)
		return (-1);
	va_start(args, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == '\0')
				return (len);
			len += ft_optimize(args, s[i + 1]);
			i++;
		}
		else
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (len);
}
