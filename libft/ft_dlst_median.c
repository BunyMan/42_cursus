/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_median.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:47:21 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/03/13 16:47:32 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dlst_median(t_stack *stack)
{
	t_stack	*dup;
	int		half;

	half = ft_dlst_size(stack) / 2;
	dup = ft_dlst_duplicate(stack);
	ft_dlst_sort(&dup);
	return (ft_dlst_get(dup, half - 1));
}
