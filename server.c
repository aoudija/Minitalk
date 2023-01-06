/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:39:37 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/06 15:49:51 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	power(int n, int p)
{
	if (p == 0)
		return (1);
	return (power(n, p - 1) * n);
}

int	*binary_to_decimal(char *bn)
{
	int	*table;
	int	i;
	int	j;
	int	k;
	int	x;

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
	return (msg);
}

void	sig_handler(int sig)
{
	static int	ct = 0;
	static char	*g;
	char		*s;

	if (!g)
		g = ft_strdup("");
	if (sig == 30)
		g = ft_strjoin(g, "0");
	else if (sig == 31)
		g = ft_strjoin(g, "1");
	ct++;
	if (ct == 8)
	{
		s = decimal_to_msg(binary_to_decimal(g));
		write(1, &s[0], 1);
		free(g);
		g = NULL;
		free(s);
		ct = 0;
	}
}

int	main(void)
{
	printf("%d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		pause();
	}
}
