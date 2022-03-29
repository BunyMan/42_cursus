/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:49:45 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/03/13 20:43:48 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlst_remove(t_stack **stack)
{
	t_stack	*temporary;

	if (!stack)
		return ;
	temporary = *stack;
	if (temporary->next)
		temporary->next->prev = temporary->prev;
	if (temporary->prev)
		temporary->prev->next = temporary->next;
	if (temporary->prev)
		*stack = temporary->prev;
	else
		*stack = temporary->next;
	free(temporary);
}
