/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:51:16 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/03/13 16:51:25 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  create new node in the end of the stack
*/

void	ft_dlstadd_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last;

	if (!*stack)
		*stack = new_node;
	else
	{
		last = ft_dlst_last(*stack);
		new_node->prev = last;
		last->next = new_node;
	}
}
