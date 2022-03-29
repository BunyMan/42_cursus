/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstis_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:51:55 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/03/13 16:52:03 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  checks if there is a duplicate number
*/

int	ft_dlstis_dup(t_stack *stack)
{
	t_stack	*sorted;

	sorted = ft_dlst_duplicate(stack);
	ft_dlst_sort(&sorted);
	while (sorted->next)
	{
		if (sorted->data == sorted->next->data)
			return (1);
		sorted = sorted->next;
	}
	ft_dlst_clear(&sorted);
	return (0);
}
