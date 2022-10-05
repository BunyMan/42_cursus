/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:05:49 by jbuny-fe          #+#    #+#             */
/*   Updated: 2021/10/31 18:43:43 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*help;

	if (!*lst)
		return ;
	while (*lst != NULL)
	{
		help = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = help;
	}
	lst = NULL;
}
