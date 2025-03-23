/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:59:51 by mbelkass          #+#    #+#             */
/*   Updated: 2025/03/22 02:43:42 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_two(t_stack *stack)
{
    if (stack->value > stack->next->value)
    {
        sa(stack);
    }
}
void    sort_three(t_stack **stack)
{
    if (ifsorted(*stack) == 0)
        return;
    if ((*stack)->value > (*stack)->next->value)
        sa(*stack);
    if ((*stack)->next->value > (*stack)->next->next->value)
        rra(stack);
    if ((*stack)->value > (*stack)->next->value)
        sa(*stack);
}

static int    min_index(t_stack *stack)
{
    int min;
    int i;
    int ret;

    i = 0;
    ret = 0;
    min = stack->value;
    while (stack)
    {
        if (min > stack->value)
        {
            min = stack->value;
            ret = i;
        }
        i++;
        stack = stack->next;
    }
    return(ret);
}

void    sort_four(t_stack **stack_a, t_stack **stack_b)
{
    while (min_index(*stack_a) != 0)
    {
        ra(stack_a);
    }
    if (ifsorted(*stack_a) == 0)
        return;
    pb(stack_a, stack_b);
    sort_three(stack_a);
    pa(stack_a, stack_b);
}

void    sort_five(t_stack **stack_a, t_stack **stack_b)
{
    int index;
    
    index = min_index(*stack_a);
    while (index != 0)
    {
        if (index <= 2)
            ra(stack_a);
        else 
            rra(stack_a);
        index = min_index(*stack_a); 
    }
    if (ifsorted(*stack_a) == 0)
        return;
    pb(stack_a, stack_b);
    sort_four(stack_a, stack_b);
    pa(stack_a, stack_b);
}
