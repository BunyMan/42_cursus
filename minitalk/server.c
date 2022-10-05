/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD
/*   server.c                                           :+:      :+:    :+:   */
=======
/*   main_server.c                                      :+:      :+:    :+:   */
>>>>>>> a8452498e625bbb3b411135b5c700aced805b666
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:52:43 by jbuny-fe          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/26 09:23:26 by jbuny-fe         ###   ########.fr       */
=======
/*   Updated: 2022/05/26 10:52:48 by jbuny-fe         ###   ########.fr       */
>>>>>>> a8452498e625bbb3b411135b5c700aced805b666
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_sigaction(int sig, siginfo_t *sinfo, void *context)
{
	static int		i = 0;
	static pid_t	cpid = 0;
	static char		c = 0;

	(void)context;
	if (!cpid)
		cpid = sinfo->si_pid;
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(cpid, SIGUSR2);
			cpid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill(cpid, SIGUSR1);
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	s_sigaction.sa_sigaction = ft_sigaction;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
<<<<<<< HEAD


=======
>>>>>>> a8452498e625bbb3b411135b5c700aced805b666
