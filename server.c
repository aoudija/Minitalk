/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:39:37 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/09 11:19:11 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*opt(int sig, char *g)
{
	if (sig == 30)
		g = ft_strjoin(g, "0");
	else if (sig == 31)
		g = ft_strjoin(g, "1");
	return (g);
}

void	sig_handler(int sig, siginfo_t *info, void *context )
{
	static int		ct;
	static char		*g;
	static pid_t	pid;

	if (pid != info->si_pid && g != 0)
	{
		free(g);
		g = NULL;
		ct = 0;
	}
	if (!g)
	{
		pid = info->si_pid;
		g = ft_strdup("");
	}
	g = opt(sig, g);
	ct++;
	if (ct == 8)
	{
		ft_optimize(g);
		g = NULL;
		ct = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_putnbr_fd(getpid());
	ft_putstr_fd("\n");
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
}
