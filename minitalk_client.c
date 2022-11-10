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

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	int	j;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		j = 0;
		while (j < argv[2][i])
		{
			kill(pid, SIGUSR1);
			usleep(5);
			j++;
		}
		kill(pid, SIGUSR2);
		usleep(5);
		i++;
	}
	return (0);
}
