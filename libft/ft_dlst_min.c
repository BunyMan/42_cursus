/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:47:48 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/03/13 16:48:03 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  finds the smallest number
*/

int	ft_dlst_min(t_stack *stack)
{
	int	min_value;

	min_value = stack->data;
	while (stack)
	{
		if (stack->data < min_value)
			min_value = stack->data;
		stack = stack->next;
	}
	return (min_value);
}
