/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 19:26:48 by mbelkass          #+#    #+#             */
/*   Updated: 2025/03/24 01:09:17 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_to_last;

	if (!(*stack) || !(*stack)->next)
		return ;
	last = *stack;
	second_to_last = NULL;
	while (last->next)
	{
		second_to_last = last;
		last = last->next;
	}
	last->next = *stack;
	second_to_last->next = NULL;
	*stack = last;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_to_last;

	if (!(*stack) || !(*stack)->next)
		return ;
	last = *stack;
	second_to_last = NULL;
	while (last->next)
	{
		second_to_last = last;
		last = last->next;
	}
	last->next = *stack;
	second_to_last->next = NULL;
	*stack = last;
	write(1, "rrb\n", 4);
}

void	reverse_rot_x(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_to_last;

	if (!(*stack) || !(*stack)->next)
		return ;
	last = *stack;
	second_to_last = NULL;
	while (last->next)
	{
		second_to_last = last;
		last = last->next;
	}
	last->next = *stack;
	second_to_last->next = NULL;
	*stack = last;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rot_x(stack_a);
	reverse_rot_x(stack_b);
	write(1, "rrr\n", 4);
}
