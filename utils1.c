/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvrm <mvrm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 06:21:19 by mosakura          #+#    #+#             */
/*   Updated: 2025/12/07 17:13:08 by mvrm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_node *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 1;
	while (stack->next)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_node	*return_cheapest(t_node *stack)
{
	if (NULL == stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_node	*find_smallest(t_node *stack)
{
	long			smallest;
	t_node	*smallest_node;

	if (NULL == stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

void	append_node(t_node **stack, int nbr)
{
	t_node	*node;
	t_node	*last_node;

	if (NULL == stack)
		return ;
	node = malloc(sizeof(t_node));
	if (NULL == node)
		return ;
	node->next = NULL;
	node->value = nbr;
	/* initialize metadata to safe defaults */
	node->position = 0;
	node->f_idx = 0;
	node->price = 0;
	node->above_median = false;
	node->cheapest = false;
	node->target = NULL;
	if (NULL == *stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

t_node	*find_last_node(t_node *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

int	stack_len(t_node *stack)
{
	return (ft_lstsize(stack));
}
