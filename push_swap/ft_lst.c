/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 05:35:47 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/03/18 04:28:25 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*element;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	element = *lst;
	while (element->next)
		element = element->next;
	element->next = new;
}

t_list	*ft_lstnew(int content)
{
	t_list	*res;

	res = (t_list *)malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->next = NULL;
	res->content = content;
	return (res);
}

void	ft_lst_clear(t_list **stack)
{
	t_list	*nxt;

	while (*stack)
	{
		nxt = *stack;
		*stack = (*stack)->next;
		nxt->content = 0;
		free(nxt);
	}
}

int	ft_lst_size(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
