/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:00:05 by jbuny-fe          #+#    #+#             */
/*   Updated: 2022/03/13 20:42:28 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void	*ft_memset(void *str, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	ft_bzero(void *b, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int i);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_lstsize(t_list *lst);
int		ft_str_isnumeric(char *str);
int		ft_isint(long long int n);

char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(const char *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*ft_dlst_first(t_stack *stack);
t_stack	*ft_dlst_last(t_stack *stack);
t_stack	*ft_dlst_new(int content);
int		ft_dlst_size(t_stack *stack);
void	ft_dlstadd_back(t_stack **stack, t_stack *new_node);
void	ft_dlstadd_front(t_stack **stack, t_stack *new_node);
int		ft_dlstis_dup(t_stack *stack);
int		ft_dlstis_sorted(t_stack *stack);
int		ft_dlst_max(t_stack *stack);
int		ft_dlst_min(t_stack *stack);
void	ft_dlst_remove(t_stack **stack);
void	ft_dlst_clear(t_stack **stack);
void	ft_dlst_print(t_stack *stack);
t_stack	*ft_dlst_duplicate(t_stack *stack);
int		ft_dlst_find(t_stack *stack, int value);
int		ft_dlst_get(t_stack *stack, int position);
int		ft_dlst_has_bigger(t_stack *stack, int value);
int		ft_dlst_median(t_stack *stack);
void	ft_dlst_sort(t_stack **stack);
t_stack	*ft_dlst_split(t_stack *head);
t_stack	*ft_merge_sort(t_stack *first, t_stack *second);

#endif
