/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 06:19:54 by mbelkass          #+#    #+#             */
/*   Updated: 2025/03/23 06:49:59 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void leaks(void)
{
    system("leaks push_swap");
}

t_stack  *create_node(int value)
{
    t_stack  *new_node;

    new_node = (t_stack *)malloc(sizeof(t_stack));
    if (!new_node)
        return (NULL);
    new_node->value = value;
    new_node->next = NULL;
    return (new_node);
}

void push(int value, t_stack **stack_a)
{
    t_stack *current;
    t_stack *newnode;

    newnode = create_node(value);
    if(!newnode)
        freethelist(newnode);
    if (!*stack_a)
    {
        *stack_a = newnode;
        return;
    }
    current = *stack_a;
    while (current->next)
        current = current->next;
    current->next = newnode;
}

void print_stack(t_stack *stack)
{
    t_stack *temp;
    
    if (!stack)
    {
        printf("Empty\n");
        return;
    }
    
    temp = stack;
    while (temp)
    {
        printf("%d", temp->value);
        temp = temp->next;
        printf("\n");
    }
}

void    fill_stack(t_stack **stack, char **argv, int argc)
{
    int     i;
    int     j;
    char    **string;
    long     value;

    i = 1;
    while (i < argc)
    {
        j = 0;
        string = ft_split(argv[i], ' ');
        if (!string)
            free_strings(string);
        while (string[j])
        {
            value = ft_atoi(string[j]);
            if (value > INT_MAX || value < INT_MIN)
            {
                write(2, "Error\n", 6);
                free_strings(string);
                freethelist(*stack);
                exit(1);
            }
            push(value, stack);
            j++;
        }
        free_strings(string);
        i++;
    }
}

static int     count_num(t_stack *stack)
{
    int size;
    
    size = 0;
    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return (size);
}

int main(int argc,char **argv)
{
    
    t_stack     *stack_a = NULL;
    t_stack     *stack_b = NULL;
    int     len;
    
    // atexit(leaks);
    if (argc)
    {
        ft_parsing(argv);
        fill_stack(&stack_a, argv, argc);
        len = count_num(stack_a);
        if (ifduplicated(stack_a) == 1 || ifsorted(stack_a) == 0)
        {
            freethelist(stack_a);
            write(2, "Error\n", 6);
            exit(1);
        }    
        if (len == 2)
            sort_two(stack_a);
        else if (len == 3)
            sort_three(&stack_a);
        else if (len == 4)
            sort_four(&stack_a, &stack_b);
        else if (len == 5)
            sort_five(&stack_a, &stack_b);
        else
            range1(&stack_a, &stack_b);
    }
    freethelist(stack_a);
    freethelist(stack_b);
}
