/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:43:03 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/03/13 16:43:17 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** returns th index of a value if it exists in stack
** if it doesn't find the value, it returns INT_MIN.
*/

int	ft_dlst_find(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (value == stack->data)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-2147483648);
}
