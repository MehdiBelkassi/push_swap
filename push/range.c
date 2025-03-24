/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 07:03:14 by mbelkass          #+#    #+#             */
/*   Updated: 2025/03/24 02:28:47 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;

	current = stack;
	while (current)
	{
		current->index = 0;
		compare = stack;
		while (compare)
		{
			if (current->value > compare->value)
				current->index++;
			compare = compare->next;
		}
		current = current->next;
	}
}

int	lstsize(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	find_max(t_stack *stack)
{
	int	pos;
	int	size;

	pos = 0;
	size = lstsize(stack);
	while (stack)
	{
		if (stack->index == size - 1)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (pos);
}

void	range_b(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pos;

	size = lstsize(*stack_b);
	while (*stack_b)
	{
		pos = find_max(*stack_b);
		size = lstsize(*stack_b);
		if (pos <= size / 2)
		{
			if (pos == 0)
			{
				pa(stack_a, stack_b);
			}
			else
				rb(stack_b);
		}
		else
		{
			rrb(stack_b);
		}
	}
}

void	range1(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	range;
	int	min;

	min = 0;
	size = lstsize(*stack_a);
	indexing(*stack_a);
	range = size * 0.05 + 10;
	while (*stack_a)
	{
		if ((*stack_a)->index <= range)
		{
			pb(stack_a, stack_b);
			if ((*stack_b)->index < min)
				rb(stack_b);
			min++;
			range++;
		}
		else if ((*stack_a)->index > range)
		{
			ra(stack_a);
		}
	}
	range_b(stack_a, stack_b);
}
