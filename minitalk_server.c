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

void	sig_handler(int signum)
{
	(void)signum;
	ft_printf("Received signal\n");
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, sig_handler);
	pause();
	return (0);
}
