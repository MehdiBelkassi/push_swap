/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 01:05:53 by mbelkass          #+#    #+#             */
/*   Updated: 2025/03/24 01:09:27 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack)
{
	t_stack	*second;
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	second = (*stack)->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = *stack;
	(*stack)->next = NULL;
	*stack = second;
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack)
{
	t_stack	*second;
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	second = (*stack)->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = *stack;
	(*stack)->next = NULL;
	*stack = second;
	write(1, "rb\n", 3);
}

void	rotate_x(t_stack **stack)
{
	t_stack	*second;
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	second = (*stack)->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = *stack;
	(*stack)->next = NULL;
	*stack = second;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_x(stack_a);
	rotate_x(stack_b);
	write(1, "rr\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!stack_a || !(*stack_a))
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	write(1, "pb\n", 3);
}
