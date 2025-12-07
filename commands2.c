/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvrm <mvrm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 05:45:42 by mosakura          #+#    #+#             */
/*   Updated: 2025/12/07 17:13:09 by mvrm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a, bool bl)
{
	t_node  *first;
	t_node  *second;
	t_node  *last;
	int     len;

	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	len = stack_len(*a);
	if (len == 1)
		return ;
	first = *a;
	second = first->next;
	last = find_last_node(first);
	/* detach first and move it to end */
	last->next = first;
	first->prev = last;
	first->next = NULL;
	second->prev = NULL;
	*a = second;
	if (bl)
		write(STDOUT_FILENO, "ra\n", 3);
}

void	rb(t_node **b, bool bl)
{
	t_node  *first;
	t_node  *second;
	t_node  *last;

	if (b == NULL || *b == NULL || (*b)->next == NULL)
		return ;
	first = *b;
	second = first->next;
	last = find_last_node(first);
	last->next = first;
	first->prev = last;
	first->next = NULL;
	second->prev = NULL;
	*b = second;
	if (bl)
		write(STDOUT_FILENO, "rb\n", 3);
}

void	rr(t_node **a, t_node **b, bool bl)
{
	ra(a, false);
	rb(b, false);
	if (bl)
		write(STDOUT_FILENO, "rr\n", 3);
}

void	rra(t_node **a, bool bl)
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
	if (bl)
		write(STDOUT_FILENO, "rra\n", 4);
}

void	rrb(t_node **b, bool bl)
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
	if (bl)
		write(STDOUT_FILENO, "rrb\n", 4);
}
