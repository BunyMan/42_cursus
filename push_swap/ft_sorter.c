/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 05:36:56 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/03/18 00:22:00 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print(t_list *stack, char c);

void	ft_sort3(t_list **stack)
{
	if (ft_lst_size(*stack) == 2)
	{
		ft_instruction_printer(SWAP_A, stack, NULL, 1);
		return ;
	}
	if ((*stack)->content < (*stack)->next->content
		&& (*stack)->next->content > (*stack)->next->next->content)
		ft_instruction_printer(REV_ROTATE_A, stack, NULL, 1);
	else if ((*stack)->content > (*stack)->next->content
		&& (*stack)->content > (*stack)->next->next->content)
		ft_instruction_printer(ROTATE_A, stack, NULL, 1);
	if (ft_is_sorted(*stack) == 1)
		ft_instruction_printer(SWAP_A, stack, NULL, 1);
}

void	ft_cost_executer(int up_a, int up_b, t_list **stack_a, t_list **stack_b)
{
	int	cost;
	int	size_a;
	int	size_b;
	int	down_a;
	int	down_b;

	size_a = ft_lst_size(*stack_a);
	size_b = ft_lst_size(*stack_b);
	cost = ft_cost(up_a, up_b, size_a, size_b);
	down_a = size_a - up_a;
	down_b = size_b - up_b;
	if (cost == up_a + down_b)
	{
		ft_instruction_printer(ROTATE_A, stack_a, NULL, up_a);
		ft_instruction_printer(REV_ROTATE_B, NULL, stack_b, down_b);
	}
	else if (cost == down_a + up_b)
	{
		ft_instruction_printer(REV_ROTATE_A, stack_a, NULL, down_a);
		ft_instruction_printer(ROTATE_B, NULL, stack_b, up_b);
	}
	else if (cost == ft_max(up_a, up_b))
		ft_rotate_both(up_a, up_b, stack_a, stack_b);
	else if (cost == ft_max(down_a, down_b))
		ft_rotate_both(-down_a, -down_b, stack_a, stack_b);
}

void	ft_complex(t_list **stack_a, t_list **stack_b)
{
	int	mov_a;
	int	mov_b;
	int	a;
	int	b;

	mov_a = -1;
	mov_b = -1;
	b = 1;
	while (b <= ft_lst_size(*stack_b))
	{
		a = ft_put_in_a(*stack_a, *stack_b, b);
		if (ft_cost(mov_a, mov_b, ft_lst_size(*stack_a), ft_lst_size(*stack_b))
			> ft_cost(a, b, ft_lst_size(*stack_a), ft_lst_size(*stack_b)))
		{
			mov_a = a;
			mov_b = b;
		}
		b++;
	}
	ft_cost_executer(mov_a - 1, mov_b - 1, stack_a, stack_b);
}

void	ft_sort_big(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	pos;
	int	min;

	while (ft_lst_size(*stack_a) > 3)
		ft_instruction_printer(PUSH_B, stack_a, stack_b, 1);
	ft_sort3(stack_a);
	while (ft_lst_size(*stack_b) > 0)
	{
		ft_complex(stack_a, stack_b);
		ft_instruction_printer(PUSH_A, stack_a, stack_b, 1);
	}
	size = ft_lst_size(*stack_a);
	min = lst_min(*stack_a);
	pos = ft_index(*stack_a, min);
	if ((*stack_a)->content != min)
	{
		if (pos > size / 2)
			ft_instruction_printer(REV_ROTATE_A, stack_a, NULL, size + 1 - pos);
		else
			ft_instruction_printer(ROTATE_A, stack_a, NULL, pos - 1);
	}
	return ;
}

void	ft_sort(t_list **stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
	if (ft_lst_size(*stack_a) < 4)
		ft_sort3(stack_a);
	else
		ft_sort_big(stack_a, &stack_b);
	if (ft_is_sorted(*stack_a) == 0 && stack_b == NULL)
		return ;
}
