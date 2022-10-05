/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 22:18:14 by jbuny-fe          #+#    #+#             */
/*   Updated: 2021/10/31 00:58:18 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nuno;

	nuno = malloc(sizeof(t_list));
	if (!nuno)
		return (NULL);
	nuno->content = content;
	nuno->next = NULL;
	return (nuno);
}
