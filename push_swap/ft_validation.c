/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 07:05:35 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/03/18 04:28:39 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* check if it's only digits */
int	ft_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

/* transform string to long int */
long	ft_atol(char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	sign = -1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 - (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/* checks for duplicates */
int	ft_lst_strcmp(int nb, t_list *stack)
{
	while (stack)
	{
		if (stack->content == nb)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	ft_validate(char *str, t_list **stack)
{
	int		nbr;
	long	nb;

	if (ft_digits(str) == 1)
		return (1);
	nb = ft_atol(str);
	if (nb > 2147483647 || nb < -2147483648)
		return (1);
	nbr = (int)nb;
	if (ft_lst_strcmp(nbr, *stack))
		return (1);
	if (stack == NULL)
		*stack = ft_lstnew(nbr);
	else
		ft_lstadd_back(stack, ft_lstnew(nbr));
	return (0);
}

/* this function goes through the argvs: 
validates them and stores them in the stack */
int	ft_val(int argc, char **str, t_list **stack)
{
	int		i;

	i = 1;
	if (argc == 2)
		str = ft_split(str[i--], ' ');
	while (str[i])
	{
		if (ft_validate(str[i], stack) == 1)
		{
			if (argc == 2)
			{
				while (str[i])
				{
					free(str[i]);
					i--;
				}
				free (str);
				return (1);
			}
		}
		i++;
	}
	return (0);
}
