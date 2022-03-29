/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions_printer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 05:35:34 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/03/18 04:22:46 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printer(char *str, void (*f) (t_list **), t_list **stack1,
		t_list **stack2)
{
	write(1, str, ft_strlen(str));
	if (str[0] == 'p')
	{
		ft_push(stack1, stack2);
		return ;
	}
	if (stack1)
		f(stack1);
	if (stack2)
		f(stack2);
}

void	ft_instruction_printer(int ord, t_list **stackA, t_list **stackB, int n)
{
	while (n-- > 0)
	{
		if (ord == SWAP_A)
			ft_printer("sa\n", ft_swap, stackA, NULL);
		else if (ord == SWAP_B)
			ft_printer("sb\n", ft_swap, stackB, NULL);
		else if (ord == SWAP_A_B)
			ft_printer("ss\n", ft_swap, stackA, stackB);
		else if (ord == PUSH_A)
			ft_printer("pa\n", NULL, stackB, stackA);
		else if (ord == PUSH_B)
			ft_printer("pb\n", NULL, stackA, stackB);
		else if (ord == ROTATE_A)
			ft_printer("ra\n", ft_rotate, stackA, NULL);
		else if (ord == ROTATE_B)
			ft_printer("rb\n", ft_rotate, stackB, NULL);
		else if (ord == ROTATE_A_B)
			ft_printer("rr\n", ft_rotate, stackA, stackB);
		else if (ord == REV_ROTATE_A)
			ft_printer("rra\n", ft_rrotate, stackA, NULL);
		else if (ord == REV_ROTATE_B)
			ft_printer("rrb\n", ft_rrotate, stackB, NULL);
		else if (ord == REV_ROTATE_A_B)
			ft_printer("rrr\n", ft_rrotate, stackA, stackB);
	}
}

void	ft_rotate_both(int mov_a, int mov_b, t_list **stack_a, t_list **stack_b)
{
	if (mov_a + mov_b >= 0 && mov_a >= mov_b)
	{
		ft_instruction_printer(ROTATE_A_B, stack_a, stack_b, mov_b);
		ft_instruction_printer(ROTATE_A, stack_a, stack_b, mov_a - mov_b);
	}
	if (mov_a + mov_b >= 0 && mov_a < mov_b)
	{
		ft_instruction_printer(ROTATE_A_B, stack_a, stack_b, mov_a);
		ft_instruction_printer(ROTATE_B, stack_a, stack_b, mov_b - mov_a);
	}
	if (mov_a + mov_b < 0 && mov_a <= mov_b)
	{
		ft_instruction_printer(REV_ROTATE_A_B, stack_a, stack_b, -mov_b);
		ft_instruction_printer(REV_ROTATE_A, stack_a, stack_b, mov_b - mov_a);
	}
	if (mov_a + mov_b < 0 && mov_a > mov_b)
	{
		ft_instruction_printer(REV_ROTATE_A_B, stack_a, stack_b, -mov_a);
		ft_instruction_printer(REV_ROTATE_B, stack_a, stack_b, -mov_b + mov_a);
	}
}
