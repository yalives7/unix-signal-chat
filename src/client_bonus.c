/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungor <sungor@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 22:54:25 by sungor            #+#    #+#             */
/*   Updated: 2025/03/10 22:54:29 by sungor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minitalk_bonus.h"

static void	handler(int signum)
{
	if (signum == SIGUSR2)
	{
		write(1, "Message Delivered\n", 19);
		exit(0);
	}
}

static void	send_character(char c, int pid)
{
	int	i;

	i = 8;
	while (i-- > 0)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(0);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(0);
		}
		usleep(700);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = -1;
	signal(SIGUSR2, &handler);
	signal(SIGUSR1, &handler);
	if (argc == 3)
	{
		pid = ft_safe_atoi(argv[1]);
		if (pid > 0)
		{
			while (argv[2][++i])
				send_character(argv[2][i], pid);
			send_character('\0', pid);
		}
		else
			write(1, "Invalid PID\n", 13);
	}
	else
		write(1, "./client_bonus [server_bonus pid] [message]\n", 45);
}
