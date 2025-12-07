/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvrm <mvrm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 08:04:01 by mosakura          #+#    #+#             */
/*   Updated: 2025/12/07 17:13:09 by mvrm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_node **a,
						t_node **b,
						t_node *cheapest_node)
{
	while (*a != cheapest_node->target
		&& *b != cheapest_node)
		rr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

static void	reverse_rotate_both(t_node **a,
								t_node **b,
								t_node *cheapest_node)
{
	while (*a != cheapest_node->target
		&& *b != cheapest_node)
		rrr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

void	finish_rotation(t_node **stack,
							t_node *top_node,
							char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

static void	move_nodes(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->above_median
		&& cheapest_node->target->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target, 'a');
	pa(a, b, false);
}

void	push_swap(t_node **a, t_node **b)
{
	t_node	*smallest;
	int				len_a;

	len_a = stack_len(*a);
	if (len_a == 5)
		handle_five(a, b);
	else
	{
		while (len_a-- > 3)
			pb(b, a, false);
	}
	tiny_sort(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_current_position(*a);
	smallest = find_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}

bool	stack_sorted(t_node *a)
{
	if (!a)
		return (true);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (false);
		a = a->next;
	}
	return (true);
}

void	tiny_sort(t_node **a)
{
	/* simple 2-3 element sort using available ops */
	if (stack_len(*a) == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, true);
		return ;
	}
	/* 3 elements - brute force minimal sequence */
	while (!stack_sorted(*a))
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, true);
		else if ((*a)->next->value > (*a)->next->next->value)
			rra(a, true);
		else
			ra(a, true);
	}
}

void	free_stack(t_node **a)
{
	t_node *tmp;

	if (!a || !*a)
		return;
	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
	*a = NULL;
}

void	free_matrix(char **m)
{
	int i = 0;

	if (!m)
		return;
	while (m[i])
		free(m[i++]);
	free(m);
}

void	handle_five(t_node **a, t_node **b)
{
	/* move two smallest to b, tiny_sort a, then pa twice */
	while (stack_len(*a) > 3)
	{
		t_node *small = find_smallest(*a);
		set_current_position(*a);
		if (small->above_median)
			while (*a != small)
				ra(a, true);
		else
			while (*a != small)
				rra(a, true);
		pb(b, a, true);
	}
	tiny_sort(a);
	while (*b)
		pa(a, b, true);
}
