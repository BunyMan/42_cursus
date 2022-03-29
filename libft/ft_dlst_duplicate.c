/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_duplicate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:42:32 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/03/13 16:42:45 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  copies a stack and creates a duplicate
*/

t_stack	*ft_dlst_duplicate(t_stack *stack)
{
	t_stack	*dup;
	t_stack	*new_node;

	dup = 0;
	while (stack)
	{
		new_node = ft_dlst_new(stack->data);
		if (!new_node)
		{
			ft_dlst_clear(&dup);
			return (0);
		}
		ft_dlstadd_back(&dup, new_node);
		stack = stack->next;
	}
	return (dup);
}
