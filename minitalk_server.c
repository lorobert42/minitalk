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
#include "libft/libft.h"
#include "minitalk.h"

t_char	g_c;

void	sig_handler(int signum)
{
	if (signum == SIGUSR1)
		g_c.c = (g_c.c << 1) + 1;
	else
		g_c.c = (g_c.c << 1);
	g_c.bits++;
	if (g_c.bits == 8)
	{
		write(1, &g_c.c, 1);
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
	sigaction(SIGUSR1, &act1, &oldact1);
	act2.sa_handler = sig_handler;
	sigaction(SIGUSR2, &act2, &oldact2);
	g_c.c = 0;
	g_c.bits = 0;
	while (1)
	{
		pause();
	}
	sigaction(SIGUSR1, &oldact1, NULL);
	sigaction(SIGUSR2, &oldact2, NULL);
	return (0);
}
