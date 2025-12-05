/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 05:45:42 by mosakura          #+#    #+#             */
/*   Updated: 2025/12/05 08:34:06 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a, bool bl)
{
	t_node	*last_node;
	int		len;

	len = stack_len(*a);
	if (NULL == a || NULL == *a || 1 == len)
		return ;
	last_node = find_last_node(*a);
	last_node->next = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
	if (bl)
		write(STDOUT_FILENO, "ra\n", 3);
}

void	rb(t_node **b, bool bl)
{
	t_node	*last_node;
	int		len;

	len = stack_len(*b);
	if (NULL == b || NULL == *b || 1 == len)
		return ;
	last_node = find_last_node(*b);
	last_node->next = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
	if (bl)
		write(STDOUT_FILENO, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	ra(a, false);
	rb(b, false);
	write(STDOUT_FILENO, "rr\n", 3);
}

void	rra(t_node **a)
{
	t_node	*last;
	int		len;

	len = stack_len(*a);
	if (NULL == *a || NULL == a || 1 == len)
		return ;
	last = find_last_node(*a);
	last->prev->next = NULL;
	last->next = *a;
	last->prev = NULL;
	*a = last;
	last->next->prev = last;
}

void	rrb(t_node **b)
{
	t_node	*last;
	int		len;

	len = stack_len(*b);
	if (NULL == *b || NULL == b || 1 == len)
		return ;
	last = find_last_node(*b);
	last->prev->next = NULL;
	last->next = *b;
	last->prev = NULL;
	*b = last;
	last->next->prev = last;
}
