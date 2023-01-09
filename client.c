/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:24:33 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/09 11:43:33 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*decimal_to_binary(int n)
{
	int		nb;
	char	*str;
	int		i;
	int		j;

	i = 0;
	nb = n;
	while (nb > 0)
	{
		nb = nb / 2;
		i++;
	}
	str = malloc(8);
	str[8] = 0;
	j = 8 - i;
	i = 7;
	while (n > 0)
	{
		str[i] = n % 2 + '0';
		n = n / 2;
		i--;
	}
	str = ft_memset(str, '0', j);
	return (str);
}

char	**msg_in_binary(char *str)
{
	int		*msg2;
	char	**s;
	size_t	len;
	size_t	n;

	len = ft_strlen(str);
	n = 0;
	msg2 = malloc(len * sizeof(int));
	while (n < len)
	{
		msg2[n] = (int)str[n];
		n++;
	}
	n = 0;
	s = malloc (sizeof(char *) * (len + 1));
	while (n < len)
	{
		s[n] = decimal_to_binary(msg2[n]);
		n++;
	}
	s[n] = 0;
	return (s);
}

int	ft_isdigit(int c)
{
	if (c <= 57 && c >= 48)
		return (1);
	return (0);
}

void	client(int pid, char *str)
{
	char	**s;
	int		i;
	int		j;
	char	c;

	j = 0;
	s = msg_in_binary(str);
	while (s[j])
	{
		i = 0;
		while (s[j][i])
		{
			if (s[j][i] == '0')
				kill(pid, SIGUSR1);
			else if (s[j][i] == '1')
				kill(pid, SIGUSR2);
			usleep(700);
			i++;
		}
		j++;
	}
	ft_free(s);
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc != 3)
	{
		ft_putstr_fd("\x1B[31mERROR : ./client + pid + message\n");
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		if (ft_isdigit((int)argv[1][i]) == 0)
		{
			ft_putstr_fd("\x1B[31mwrong pid\n");
			return (0);
		}
		i++;
	}
	client(ft_atoi(argv[1]), argv[2]);
}
