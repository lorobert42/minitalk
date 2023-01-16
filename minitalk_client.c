/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:56 by lorobert          #+#    #+#             */
/*   Updated: 2023/01/16 12:54:22 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

void	ft_error(char *str)
{
	ft_printf("%s", str);
	exit(0);
}

void	send_char(unsigned char c, int pid)
{
	int	i;

	i = 6;
	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error("Error sending signal\n");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error("Error sending signal\n");
		}
		usleep(200);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int				pid;
	int				i;

	if (argc != 3)
	{
		ft_printf("Usage: ./client [server pid] [message]\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (0);
	i = 0;
	while (argv[2][i])
	{
		send_char(argv[2][i], pid);
		usleep(200);
		i++;
	}
	return (0);
}
