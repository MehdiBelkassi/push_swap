/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:59:40 by mbelkass          #+#    #+#             */
/*   Updated: 2025/03/22 02:37:06 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    free_strings(char **str)
{
    int     i;

    i = 0;
    while (str[i])
    {
        free (str[i]);
        i++;
    }
    free(str);
}

void    freethelist(t_stack *stack)
{
    t_stack *tmp;

    while (stack)
    {
        tmp = stack->next;
        free(stack);
        stack = tmp;
    }
}

long	ft_atoi(const char *str)
{
	long			i;
	long 			res;
	long			sign;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	return (res * sign);
}