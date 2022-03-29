/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 05:37:44 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/03/17 07:01:52 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_put_in_a_aux(t_list *stack, int nb)
{
	int	size;
	int	i;

	size = ft_lst_size(stack);
	i = 1;
	if (nb < lst_min(stack))
		return (ft_index(stack, lst_min(stack)));
	while (nb < stack->content && i++ < size && stack->next)
		stack = stack->next;
	while (nb > stack->content && i++ < size && stack->next)
		stack = stack->next;
	return (i);
}

/* returns the index where it should be placed in stack a */
int	ft_put_in_a(t_list *stack_a, t_list *stack_b, int pos)
{
	int	nb;
	int	i;
	int	j;

	j = 0;
	while (++j < pos)
		stack_b = stack_b->next;
	nb = stack_b->content;
	i = 1;
	if (nb > lst_max(stack_a))
		return (ft_index(stack_a, lst_max(stack_a)) + 1);
	if (nb < stack_a->content && nb > last_stack(stack_a))
		return (1);
	if (nb > stack_a->content)
	{
		while (nb > stack_a->content && i++ > 0 && stack_a->next)
			stack_a = stack_a->next;
		return (i);
	}
	i = ft_put_in_a_aux(stack_a, nb);
	return (i);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

/* trying the 4 potential plays: both up, both down and
mixing up and down.
When using the different direction I will have to do all 
the moves, when it's the same direction, I can save moves
by moving both stacks at the same time and then doing the
extra moves I need on the other stack */
int	ft_cost(int up_a, int up_b, int size_a, int size_b)
{
	int	cost;
	int	down_a;
	int	down_b;

	if (up_a < 0 && up_b < 0)
		return (size_a + size_b);
	down_a = size_a - up_a;
	down_b = size_b - up_b;
	cost = up_a + down_b;
	if (cost > down_a + up_b)
		cost = down_a + up_b;
	if (cost > ft_max(up_a, up_b))
		cost = ft_max(up_a, up_b);
	if (cost > ft_max(down_a, down_b))
		cost = ft_max(down_a, down_b);
	return (cost);
}
