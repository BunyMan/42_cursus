/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 07:02:17 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/03/17 07:03:23 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_min(t_list *stack)
{
	int	nb;

	nb = stack->content;
	while (stack)
	{
		if (nb > stack->content)
			nb = stack->content;
		stack = stack->next;
	}
	return (nb);
}

int	lst_max(t_list *stack)
{
	int	nb;

	nb = stack->content;
	while (stack)
	{
		if (nb < stack->content)
			nb = stack->content;
		stack = stack->next;
	}
	return (nb);
}

int	ft_index(t_list *stack, int nb)
{
	int	i;

	i = 1;
	while (stack)
	{
		if (stack->content == nb)
			break ;
		i++;
		stack = stack->next;
	}
	return (i);
}

int	last_stack(t_list *stack)
{
	int	nb;

	while (stack->next)
		stack = stack->next;
	nb = stack->content;
	return (nb);
}
