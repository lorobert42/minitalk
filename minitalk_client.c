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
#include "libft/libft.h"

int main(int argc, char **argv)
{
	int	pid;

	(void)argc;
	pid = ft_atoi(argv[1]);
	kill(pid, SIGUSR1);
	return 0;
}
