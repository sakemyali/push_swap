/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 23:05:32 by mosakura          #+#    #+#             */
/*   Updated: 2025/12/05 08:26:25 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> //malloc, free
# include <limits.h>
# include <stdbool.h>
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
int		ft_lstsize(t_node *stack);
t_node	*return_cheapest(t_node *stack);
t_node	*find_smallest(t_node *stack);
void	append_node(t_node **stack, int nbr);
t_node	*find_last_node(t_node *head);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **b, t_node **a);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node b);
long	ft_atol(const char *str);

#endif
