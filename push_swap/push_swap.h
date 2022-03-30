/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 07:05:56 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/03/18 04:28:54 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

typedef enum e_ops
{
	SWAP_A = 1,
	SWAP_B,
	SWAP_A_B,
	PUSH_A,
	PUSH_B,
	ROTATE_A,
	ROTATE_B,
	ROTATE_A_B,
	REV_ROTATE_A,
	REV_ROTATE_B,
	REV_ROTATE_A_B,
}	t_ops;

/* split */
int		ft_words(char const *str, char del);
int		ft_strlen(char *str);
char	*ft_strdpl(char const *str, char del, char *res, int *counter);
char	**ft_split(char const *s, char c);

/* gnl */
char	*ft_subdup(char *str);
char	*ft_strdup(char *str, char c);
char	*ft_strjoin(char *str1, char *str2);
int		ft_check_line(char *str);
char	*get_next_line(void);

/* validations */
int		ft_digits(char *str);
long	ft_atol(char *str);
int		ft_lst_strcmp(int nb, t_list *stack);
int		ft_val(int argc, char **str, t_list **stack);
int		ft_validate(char *str, t_list **stack);

/* lists */
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
void	ft_lst_clear(t_list **stack);
int		ft_lst_size(t_list *stack);

/* instructions */
int		ft_is_sorted(t_list *stack);
void	ft_swap(t_list **stack);
void	ft_push(t_list **stack_source, t_list **stack_dest);
void	ft_rotate(t_list **stack);
void	ft_rrotate(t_list **stack);
void	ft_instruction_printer(int ord, t_list **stackA, t_list **stackB,
			int n);

/* sort utils */
int		lst_min(t_list *stack);
int		lst_max(t_list *stack);
int		ft_index(t_list *stack, int nb);
int		last_stack(t_list *stack);
int		ft_put_in_a(t_list *stack_a, t_list *stack_b, int pos);
int		ft_max(int a, int b);
int		ft_cost(int up_a, int up_b, int size_a, int size_b);

/* sort */
void	ft_sort3(t_list **stack);
void	ft_rotate_both(int mov_a, int mov_b, t_list **stack_a,
			t_list **stack_b);
void	ft_cost_executer(int up_a, int up_b, t_list **stack_a,
			t_list **stack_b);
void	ft_complex(t_list **stack_a, t_list **stack_b);
void	ft_sort_big(t_list **stack_a, t_list **stack_b);
void	ft_sort(t_list **stack_a);

#endif
