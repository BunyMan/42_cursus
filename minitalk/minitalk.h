/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:18:07 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/05/26 10:02:58 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <stdio.h>

size_t		ft_strlen(const char *str);
long int	ft_atoi(const char *str);
void		ft_putstr_fd(char *str, int fd);
void		ft_putnbr_fd(int nb, int fd);
void		ft_putchar_fd(char c, int fd);
int			ft_isdigit(int c);

#endif
