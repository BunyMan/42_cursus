/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 05:36:20 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/03/17 14:36:00 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	stack_a = NULL;
	if (argc == 1)
		return (0);
	if (ft_val(argc, argv, &stack_a) == 1)
	{
		write(2, "Error\n", 6);
		ft_lst_clear(&stack_a);
		return (1);
	}
	if (ft_is_sorted(stack_a) == 1)
		ft_sort(&stack_a);
	ft_lst_clear(&stack_a);
	return (0);
}
