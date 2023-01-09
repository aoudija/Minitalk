/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:43:19 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/09 11:13:02 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_free(char **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
}

int	power(int n, int p)
{
	if (p == 0)
		return (1);
	return (power(n, p - 1) * n);
}

int	*binary_to_decimal(char *bn)
{
	int		*table;
	int		i;
	int		j;
	size_t	k;
	int		x;

	table = ft_calloc(ft_strlen(bn), sizeof(int));
	k = 0;
	j = 0;
	x = 0;
	while (k++ < ft_strlen(bn))
	{
		if ((k + 1) % 8 == 0)
		{
			i = 7;
			while (i >= 0)
			{
				table[j] += power(2, i) * (bn[x] - '0');
				i--;
				x++;
			}
			j++;
		}
	}
	return (table);
}

char	*decimal_to_msg(int *table)
{
	int		i;
	char	*msg;

	i = 0;
	while (table[i])
		i++;
	msg = malloc(i + 1);
	i = 0;
	while (table[i])
	{
		msg[i] = (char)table[i];
		i++;
	}
	free(table);
	return (msg);
}

void	ft_optimize(char *g)
{
	char	*s;

	s = decimal_to_msg(binary_to_decimal(g));
	write(1, &s[0], 1);
	free(s);
	free(g);
}
