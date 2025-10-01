/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungor <sungor@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 22:49:32 by sungor            #+#    #+#             */
/*   Updated: 2025/03/10 22:49:35 by sungor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static int	bit = 128;
	static char	c = 0;

	(void)ucontext;
	if (sig == SIGUSR1)
	{
		c += bit;
	}
	bit /= 2;
	if (bit == 0)
	{
		write(1, &c, 1);
		if (c == '\0')
		{
			kill(info->si_pid, SIGUSR2);
		}
		bit = 128;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	ft_putstr("Server PID: ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		;
	return (0);
}
