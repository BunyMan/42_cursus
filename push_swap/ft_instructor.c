/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 05:35:09 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/03/18 04:27:32 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_list *stack)
{
	int	number;

	while (stack->next)
	{
		number = stack->content;
		stack = stack->next;
		if (number > stack->content)
			return (1);
	}
	return (0);
}

void	ft_swap(t_list **stack)
{
	int	number1;
	int	number2;
	int	size;

	size = ft_lst_size(*stack);
	if (size < 2)
		return ;
	number1 = (*stack)->content;
	number2 = (*stack)->next->content;
	(*stack)->content = number2;
	(*stack)->next->content = number1;
}

void	ft_push(t_list **stack_source, t_list **stack_dest)
{
	t_list	*temp;

	if (ft_lst_size(*stack_source) > 0)
	{
		temp = *stack_source;
		*stack_source = (*stack_source)->next;
		temp->next = *stack_dest;
		*stack_dest = temp;
	}
}

void	ft_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*new;

	if (ft_lst_size(*stack) < 2)
		return ;
	first = *stack;
	new = (*stack)->next;
	while ((*stack)->next)
		*stack = (*stack)->next;
	(*stack)->next = first;
	first->next = NULL;
	*stack = new;
}

void	ft_rrotate(t_list **stack)
{
	t_list	*temp;
	t_list	*last;

	if (ft_lst_size(*stack) < 2)
		return ;
	temp = *stack;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	last->next = *stack;
	*stack = last;
	temp->next = NULL;
}
