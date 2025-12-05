/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 05:45:45 by mosakura          #+#    #+#             */
/*   Updated: 2025/12/05 08:32:42 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a, bool bl)
{
	int	len;

	len = ft_lstsize(*a);
	if (!a || !*a || 1 == len)
		return ;
	*a = (*a)->next;
	(*a)->prev->prev = *a;
	(*a)->prev->next = (*a)->next;
	if ((*a)->next)
		(*a)->next->prev = (*a)->prev;
	(*a)->next = (*a)->prev;
	(*a)->prev = NULL;
	if (bl)
		write(STDOUT_FILENO, "sa\n", 3);
}

void	sb(t_node **b, bool bl)
{
	int	len;

	len = ft_lstsize(*b);
	if (!b || !*b || 1 == len)
		return ;
	*b = (*b)->next;
	(*b)->prev->prev = *b;
	(*b)->prev->next = (*b)->next;
	if ((*b)->next)
		(*b)->next->prev = (*b)->prev;
	(*b)->next = (*b)->prev;
	(*b)->prev = NULL;
	if (bl)
		write(STDOUT_FILENO, "sb\n", 3);
}

void	ss(t_node **a, t_node **b)
{
	sa(a, false);
	sb(b, false);
	write(STDOUT_FILENO, "ss\n", 3);
}

void	pa(t_node **a, t_node **b)
{
	t_node	*node_to_push;

	if (NULL == *b)
		return ;
	node_to_push = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	node_to_push->prev = NULL;
	if (NULL == *a)
	{
		*a = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *a;
		node_to_push->next->prev = node_to_push;
		*a = node_to_push;
	}
	write(STDOUT_FILENO, "pa\n", 3);
}

void	pb(t_node **b, t_node **a)
{
	t_node	*node_to_push;

	if (NULL == *a)
		return ;
	node_to_push = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	node_to_push->prev = NULL;
	if (NULL == *b)
	{
		*b = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *b;
		node_to_push->next->prev = node_to_push;
		*b = node_to_push;
	}
	write(STDOUT_FILENO, "pb\n", 3);
}
