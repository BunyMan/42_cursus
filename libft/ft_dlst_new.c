/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:48:19 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/03/13 16:48:31 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  create new node
*/

t_stack	*ft_dlst_new(int content)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (!stack)
		return (NULL);
	stack->data = content;
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}
