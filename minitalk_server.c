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

int	g_message;

void	sig1_handler(int signum)
{
	(void)signum;
	g_message++;
}

void	sig2_handler(int signum)
{
	(void)signum;
	write(1, &g_message, 1);
	g_message = 0;
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, sig1_handler);
	signal(SIGUSR2, sig2_handler);
	g_message = 0;
	while (1)
	{
		pause();
	}
	return (0);
}
