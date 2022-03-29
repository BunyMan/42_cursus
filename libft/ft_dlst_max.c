/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:47:01 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/03/13 16:47:10 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  finds the larger number
*/

int	ft_dlst_max(t_stack *stack)
{
	int	max_value;

	max_value = stack->data;
	while (stack)
	{
		if (stack->data > max_value)
			max_value = stack->data;
		stack = stack->next;
	}
	return (max_value);
}
