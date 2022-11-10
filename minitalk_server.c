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
	ft_printf("%d\n", getpid());
	if (signal(SIGUSR1, sig_handler) == SIG_ERR || \
		signal(SIGUSR2, sig_handler) == SIG_ERR)
		return (0);
	g_c.c = 0;
	g_c.bits = 0;
	while (1)
	{
		pause();
	}
	return (0);
}
