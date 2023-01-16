/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:47:11 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/09 14:47:15 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "minitalk.h"

t_char	g_c;

void	ft_error(char *str)
{
	ft_printf("%s", str);
	exit(0);
}

void	sig_handler(int signum)
{
	if (signum == SIGUSR1)
		g_c.c = (g_c.c << 1) + 1;
	else
		g_c.c = (g_c.c << 1);
	g_c.bits++;
	if (g_c.bits == 7)
	{
		if (write(1, &g_c.c, 1) == -1)
			ft_error("Error writing the result\n");
		g_c.c = 0;
		g_c.bits = 0;
	}
}

int	main(void)
{
	struct sigaction	act1;
	struct sigaction	act2;
	struct sigaction	oldact1;
	struct sigaction	oldact2;

	ft_printf("%d\n", getpid());
	act1.sa_handler = sig_handler;
	act1.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act1, &oldact1) != 0)
		ft_error("Error setting signal handler\n");
	act2.sa_handler = sig_handler;
	act2.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR2, &act2, &oldact2) != 0)
		ft_error("Error setting signal handler\n");
	g_c.c = 0;
	g_c.bits = 0;
	while (1)
	{
		pause();
	}
	if (sigaction(SIGUSR1, &oldact1, NULL) != 0)
		ft_error("Error restoring signal handler\n");
	if (sigaction(SIGUSR2, &oldact2, NULL) != 0)
		ft_error("Error restoring signal handler\n");
	return (0);
}
