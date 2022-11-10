/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:56 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/09 14:52:58 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

void	send_char(unsigned char c, int pid)
{
	int	j;

	j = 7;
	while (j >= 0)
	{
		if ((c >> j) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		j--;
	}
}

int	main(int argc, char **argv)
{
	int				pid;
	int				i;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (0);
	i = 0;
	while (argv[2][i])
	{
		send_char(argv[2][i], pid);
		usleep(50);
		i++;
	}
	return (0);
}
