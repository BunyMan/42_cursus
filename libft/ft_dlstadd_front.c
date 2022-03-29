/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:51:33 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/03/13 16:51:41 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  create new node in the beginning of the stack
*/

void	ft_dlstadd_front(t_stack **stack, t_stack *new_node)
{
	t_stack	*temp;

	temp = *stack;
	if (temp)
	{
		new_node->next = temp;
		temp->prev = new_node;
	}
	*stack = new_node;
}
