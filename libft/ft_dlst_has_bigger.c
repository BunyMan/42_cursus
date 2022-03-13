/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_has_bigger.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:46:06 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/03/13 16:46:19 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** checks if the stack has a bigger number than the value
*/

int	ft_dlst_has_bigger(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->data > value)
			return (1);
		stack = stack->next;
	}
	return (0);
}
