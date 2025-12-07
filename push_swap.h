/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvrm <mvrm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 23:05:32 by mosakura          #+#    #+#             */
/*   Updated: 2025/12/07 17:13:37 by mvrm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> //malloc, free
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				position;
	int				f_idx;
	int				price;
	bool			above_median;
	bool			cheapest;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target;
}					t_node;

char	**ft_split(char const *s, char c);
int	ft_lstsize(t_node *stack);
int	stack_len(t_node *stack);
t_node	*return_cheapest(t_node *stack);
t_node	*find_smallest(t_node *stack);
void	append_node(t_node **stack, int nbr);
t_node	*find_last_node(t_node *head);
void	sa(t_node **a, bool bl);
void	sb(t_node **b, bool bl);
void	ss(t_node **a, t_node **b, bool bl);
void	pa(t_node **a, t_node **b, bool bl);
void	pb(t_node **b, t_node **a, bool bl);
void	ra(t_node **a, bool bl);
void	rb(t_node **b, bool bl);
void	rr(t_node **a, t_node **b, bool bl);
void	rra(t_node **a, bool bl);
void	rrb(t_node **b, bool bl);
void	rrr(t_node **a, t_node **b, bool bl);
long	ft_atol(const char *str);

/* initialization and helpers */
void	stack_init(t_node **a, char **argv, bool flag_argc_2);
void	set_current_position(t_node *stack);
void	set_price(t_node *a, t_node *b);
void	set_cheapest(t_node *b);
void	init_nodes(t_node *a, t_node *b);
void	push_swap(t_node **a, t_node **b);

/* error and frees */
void	error_free(t_node **a, char **argv, bool flag_argc_2);
int	error_syntax(char *str_nbr);
int	error_repetition(t_node *a, int nbr);
void	free_stack(t_node **a);
void	free_matrix(char **m);

/* sorting helpers (small sets) */
bool	stack_sorted(t_node *a);
void	tiny_sort(t_node **a);
void	handle_five(t_node **a, t_node **b);

/* libft helper prototypes we rely on */
size_t	ft_strlen(const char *s);

#endif
