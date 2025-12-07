/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvrm <mvrm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 05:45:45 by mosakura          #+#    #+#             */
/*   Updated: 2025/12/07 17:13:09 by mvrm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a, bool bl)
{
	t_node  *first;
	t_node  *second;
	t_node  *third;

	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	second = first->next;
	third = second->next;
	/* perform swap */
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third)
		third->prev = first;
	*a = second;
	if (bl)
		write(STDOUT_FILENO, "sa\n", 3);
}

void	sb(t_node **b, bool bl)
{
	t_node  *first;
	t_node  *second;
	t_node  *third;

	if (b == NULL || *b == NULL || (*b)->next == NULL)
		return ;
	first = *b;
	second = first->next;
	third = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third)
		third->prev = first;
	*b = second;
	if (bl)
		write(STDOUT_FILENO, "sb\n", 3);
}

void	ss(t_node **a, t_node **b, bool bl)
{
	sa(a, false);
	sb(b, false);
	if (bl)
		write(STDOUT_FILENO, "ss\n", 3);
}

void	pa(t_node **a, t_node **b, bool bl)
{
	t_node	*node_to_push;
	if (b == NULL || *b == NULL)
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
	if (bl)
		write(STDOUT_FILENO, "pa\n", 3);
}

void	pb(t_node **b, t_node **a, bool bl)
{
	t_node	*node_to_push;
	if (a == NULL || *a == NULL)
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
	if (bl)
		write(STDOUT_FILENO, "pb\n", 3);
}
