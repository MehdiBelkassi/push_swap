/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 03:18:58 by mbelkass          #+#    #+#             */
/*   Updated: 2025/03/23 06:45:20 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack *stack)
{
    int     tmp;

    if (!stack || !stack->next)
        return;
    tmp = stack->value;
    stack->value = stack->next->value;
    stack->next->value = tmp;
    write(1, "sa\n", 3);
}

void sb(t_stack *stack)
{
    t_stack *tmp;
    int     value;

    if (!stack || !stack->next)
        return;
    tmp = stack;
    tmp = tmp->next;
    value = tmp->value;
    tmp->value = stack->value;
    stack->value = value;
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
    sa(stack_a);
    sb(stack_b);
}

void ra(t_stack **stack)
{
    t_stack *second;
    t_stack *last;

    if (!stack || !(*stack) || !(*stack)->next)
        return;
    second = (*stack)->next;
    last = *stack;
    while (last->next)
        last = last->next;
    last->next = *stack;
    (*stack)->next = NULL;
    *stack = second;
    write(1, "ra\n", 3);

}

void rb(t_stack **stack)
{
    t_stack *second;
    t_stack *last;

    if (!stack || !(*stack) || !(*stack)->next)
        return;
    second = (*stack)->next;
    last = *stack;
    while (last->next)
        last = last->next;
    last->next = *stack;
    (*stack)->next = NULL;
    *stack = second;
    write(1, "rb\n", 3);

}

void rr(t_stack **stack_a, t_stack **stack_b)
{
    ra(stack_a);
    rb(stack_b);
    write(1, "rr\n", 3);

}

void rra(t_stack **stack)
{
    t_stack *last;
    t_stack *second_to_last;

    if (!(*stack) || !(*stack)->next)
        return;
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

void rrb(t_stack **stack)
{
    t_stack *last;
    t_stack *second_to_last;

    if (!(*stack) || !(*stack)->next)
        return;
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

void rrr(t_stack **stack_a, t_stack **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}

void    pa(t_stack **stack_a, t_stack **stack_b)
{
    t_stack     *tmp;

    if (!stack_b || !(*stack_b))
        return;
    tmp = *stack_b;
    *stack_b = (*stack_b)->next;
    tmp->next = *stack_a;
    *stack_a = tmp;
    write(1, "pa\n", 3);
}

void    pb(t_stack **stack_a, t_stack **stack_b)
{
    t_stack     *tmp;

    if (!stack_a || !(*stack_a))
        return;
    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
    tmp->next = *stack_b;
    *stack_b = tmp;
    write(1, "pb\n", 3);
}
