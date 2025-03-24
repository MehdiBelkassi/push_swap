/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 06:19:54 by mbelkass          #+#    #+#             */
/*   Updated: 2025/03/24 03:05:25 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void	push(int value, t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*newnode;

	newnode = create_node(value);
	if (!newnode)
		freethelist(newnode);
	if (!*stack_a)
	{
		*stack_a = newnode;
		return ;
	}
	current = *stack_a;
	while (current->next)
		current = current->next;
	current->next = newnode;
}

void	fill_stack(t_stack **stack, char **argv, int argc)
{
	int		i;
	int		j;
	char	**string;
	long	value;

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
			checkmax(value, stack, string);
			push(value, stack);
			j++;
		}
		free_strings(string);
		i++;
	}
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = lstsize(*stack_a);
	if (len == 2)
		sort_two(*stack_a);
	else if (len == 3)
		sort_three(stack_a);
	else if (len == 4)
		sort_four(stack_a, stack_b);
	else if (len == 5)
		sort_five(stack_a, stack_b);
	else
		range1(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		ft_parsing(argv);
		fill_stack(&stack_a, argv, argc);
		if (ifsorted(stack_a) == 0)
		{
			freethelist(stack_a);
			exit(0);
		}
		if (ifduplicated(stack_a) == 1)
		{
			freethelist(stack_a);
			ft_error();
		}
		sort_stack(&stack_a, &stack_b);
	}
	else
		return (0);
	freethelist(stack_a);
	freethelist(stack_b);
}
