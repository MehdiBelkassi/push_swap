/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 03:23:10 by mbelkass          #+#    #+#             */
/*   Updated: 2025/03/23 02:08:57 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

void    ft_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

void     ft_parsing(char **argv)
{
    int i;
    int j;
  
    i = 1;
    j = 0;
    while (argv[i])
    {
        j = 0;
        while (argv[i][j] == ' ')
            j++;
        if (argv[i][j] == '\0')
            ft_error();
        while(argv[i][j])
        {
            if ((argv[i][j] < '0' || argv[i][j] > '9') && (argv[i][j] != '+' &&  argv[i][j] != '-') && (argv[i][j] != ' '))
                ft_error();
            if (argv[i][j] == '+' ||  argv[i][j] == '-')
            {
                if ((argv[i][j + 1] < '0' || argv[i][j + 1] > '9') || (argv[i][j - 1] >= '0' && argv[i][j - 1] <= '9'))
                    ft_error();
            }
            j++;
        }
        i++;
    }
}

int     ifsorted(t_stack *stack)
{
    t_stack     *current;

    current = stack;
    while (current->next)
    {
        if (current->value > current->next->value)
        {
            return (1);
        }
        current = current->next;
    }
    return (0);
}

int    ifduplicated(t_stack *stack)
{
    t_stack     *current;
    t_stack     *tmp;

    current = stack;
    tmp = stack;
    while (current)
    {
        tmp = current;
        while (tmp->next)
        {
            tmp = tmp->next;
            if (tmp->value == current->value)
                return (1);
        }
        current = current->next;
    }
    return (0);
}
