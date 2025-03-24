/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 03:18:58 by mbelkass          #+#    #+#             */
/*   Updated: 2025/03/24 01:47:32 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack)
{
	t_stack	*tmp;
	int		value;

	if (!stack || !stack->next)
		return ;
	tmp = stack;
	tmp = tmp->next;
	value = tmp->value;
	tmp->value = stack->value;
	stack->value = value;
	write(1, "sb\n", 3);
}

void	switch_x(t_stack *stack)
{
	t_stack	*tmp;
	int		value;

	if (!stack || !stack->next)
		return ;
	tmp = stack;
	tmp = tmp->next;
	value = tmp->value;
	tmp->value = stack->value;
	stack->value = value;
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_a->next)
		return ;
	if (!stack_b || !stack_b->next)
		return ;
	switch_x(stack_a);
	switch_x(stack_b);
	write(1, "ss\n", 3);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!stack_b || !(*stack_b))
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	write(1, "pa\n", 3);
}
