/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:47:13 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/06/14 00:24:57 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int			ft_printf(const char *s, ...);
int			check_type(char c);
size_t		next_arg(char c, int *char_print, va_list args);
int			ft_put_nbr_fd(int n, int fd);
int			ft_put_unsnbr_fd(unsigned int n, int fd);
int			ft_put_str_fd(char *s, int fd);
int			ft_put_char_fd(char c, int fd);
size_t		ft_strlen(const char *str);
long int	dec_hexa(unsigned long n, int fd, char *base);
void		ft_strcpy(char *src, char *dst);
int			do_thing(size_t index, char *string, int char_print, va_list args);
#endif
