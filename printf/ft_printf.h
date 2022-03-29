/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 06:15:29 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/03/15 06:42:47 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

//global contador
int	g_c;

int		formato(char a, va_list argumentos);
int		ft_printf(const char *string, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int i);
int		ft_pp(unsigned long arg_num, char *string);
int		ft_uh(long int arg_num, char *string);
int		printnum(int n);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);

#endif
