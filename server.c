/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:39:37 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/05 15:33:56 by aoudija          ###   ########.fr       */
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
	printf("@%s@\n", msg);
	return (msg);
}

char	*g_s;

void	sig_handler(int sig)
{
	int	ct;

	ct = 0;
	if (sig == 30)
	{
		g_s = ft_strjoin(g_s, "0");
		ct++;
	}
	else if (sig == 31)
	{
		g_s = ft_strjoin(g_s, "1");
		ct++;
	}
	if (ct % 8 == 0)
	{
		g_s = decimal_to_msg(binary_to_decimal(g_s));
		printf(">>%s\n", g_s);
	}
}

void	server(void)
{
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
}

int	main(void)
{
	printf("%d\n", getpid());
	while (1)
	{
		server();
		pause();
		// printf("%h")
		// printf("%s\n",decimal_to_msg(binary_to_decimal(g_s)));
		// printf("\n%s\n",decimal_to_msg(binary_to_decimal(g_s)));
	}
}
