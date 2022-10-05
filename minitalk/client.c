/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:56:11 by jbuny-fe          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/26 10:11:14 by jbuny-fe         ###   ########.fr       */
=======
/*   Updated: 2022/05/26 11:34:16 by jbuny-fe         ###   ########.fr       */
>>>>>>> a8452498e625bbb3b411135b5c700aced805b666
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
<<<<<<< HEAD
#include "stdlib.h"
=======
>>>>>>> a8452498e625bbb3b411135b5c700aced805b666

static void	ft_sigaction_(int sig)
{
	static int	i = 0;

	if (sig == SIGUSR1)
		++i;
	else
	{
<<<<<<< HEAD
		ft_putstr_fd("Received: ", 1);
=======
		ft_putstr_fd("Character(s) received: ", 1);
>>>>>>> a8452498e625bbb3b411135b5c700aced805b666
		ft_putnbr_fd(i, 1);
		ft_putstr_fd("\n", 1);
		exit(0);
	}
}

static void	send_msg(int pid, char *msg)
{
	int		bit;
	int		i;
	char	c;

	i = 0;
	while (msg[i])
	{
		bit = 8;
		c = msg[i++];
		while (bit--)
		{
			if (c >> bit & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	bit = 8;
	while (bit--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int					i;
	struct sigaction	s_sigaction;

	if (ac != 3)
	{
<<<<<<< HEAD
		ft_putstr_fd("Invalid argument count, please provide only PID and message\n", 1);
=======
		ft_putstr_fd("Invalid argument, provide only PID and message\n", 1);
>>>>>>> a8452498e625bbb3b411135b5c700aced805b666
		return (0);
	}
	i = -1;
	while (av[1][++i])
	{
		if (ft_isdigit(av[1][i]) == 0)
<<<<<<< HEAD
			ft_putstr_fd("Please provide a valid PID (only numbers) and try again\n", 1);
			return (0);
	}
	ft_putstr_fd("Sent    : ", 1);
=======
		{	
			ft_putstr_fd("Please provide a valid PID and try again\n", 1);
			return (0);
		}
	}
	ft_putstr_fd("Character(s) sent: ", 1);
>>>>>>> a8452498e625bbb3b411135b5c700aced805b666
	ft_putnbr_fd(ft_strlen(av[2]), 1);
	ft_putchar_fd('\n', 1);
	s_sigaction.sa_handler = ft_sigaction_;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	send_msg((int)ft_atoi(av[1]), av[2]);
	return (0);
}
<<<<<<< HEAD

=======
>>>>>>> a8452498e625bbb3b411135b5c700aced805b666
