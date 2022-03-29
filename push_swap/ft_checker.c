/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 05:34:25 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/03/22 14:04:44 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_instruction_exec(char *str, t_list **stackA, t_list **stackB)
{
	if (str[0] == 's' && (str[1] == 'a' || str[1] == 's'))
		ft_swap(stackA);
	if (str[0] == 's' && (str[1] == 'b' || str[1] == 's'))
		ft_swap(stackB);
	else if (str[0] == 'p' && str[1] == 'a')
		ft_push(stackB, stackA);
	else if (str[0] == 'p' && str[1] == 'b')
		ft_push(stackA, stackB);
	if (str[0] == 'r' && (str[1] == 'a' || str[1] == 'r') && str[2] == '\n')
		ft_rotate(stackA);
	if (str[0] == 'r' && (str[1] == 'b' || str[1] == 'r') && str[2] == '\n')
		ft_rotate(stackB);
	if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
		ft_rrotate(stackA);
	if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
		ft_rrotate(stackB);
	if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
	{	
		ft_rrotate(stackA);
		ft_rrotate(stackB);
	}
}

int	ft_val_instruction(char *str)
{
	if (ft_strlen(str) == 3)
	{
		if (str[0] == 's' && str[2] == '\n')
			if (str[1] == 's' || str[1] == 'a' || str[1] == 'b')
				return (1);
		if (str[0] == 'p' && str[2] == '\n')
			if (str[1] == 'a' || str[1] == 'b')
				return (1);
		if (str[0] == 'r' && str[2] == '\n')
			if (str[1] == 'a' || str[1] == 'b' || str[1] == 'r')
				return (1);
		return (0);
	}
	else if (ft_strlen(str) == 4)
	{
		if (str[0] == 'r' && str[1] == 'r' && str[3] == '\n')
			if (str[2] == 'a' || str[2] == 'b' || str[2] == 'r')
				return (1);
		return (0);
	}
	return (0);
}

int	ft_checker(t_list **stack_a)
{
	t_list	*stack_b;
	char	*str;

	stack_b = NULL;
	while (1)
	{
		str = get_next_line();
		if (str == NULL)
			break ;
		if (ft_val_instruction(str) == 0)
		{
			free(str);
			ft_lst_clear(&stack_b);
			return (2);
		}
		else
			ft_instruction_exec(str, stack_a, &stack_b);
	}
	free(str);
	ft_lst_clear(&stack_b);
	if (ft_is_sorted(*stack_a) == 1 && ft_lst_size(stack_b) == 0)
		return (0);
	else
		return (1);
}

int	main(int argc, char **argv)
{
	int		j;
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
	j = ft_checker(&stack_a);
	if (j == 2)
		write(2, "Error\n", 6);
	else if (ft_is_sorted(stack_a) == 1 && j == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lst_clear(&stack_a);
	return (0);
}
