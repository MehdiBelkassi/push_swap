/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 06:15:51 by mbelkass          #+#    #+#             */
/*   Updated: 2025/03/24 01:11:53 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

t_stack				*create_node(int value);
int					ifsorted(t_stack *stack);
void				push(int value, t_stack **stack_a);
void				fill_stack(t_stack **stack, char **argv, int argc);
char				**ft_split(char const *s, char c);
void				free_strings(char **str);
void				freethelist(t_stack *stack);
long				ft_atoi(const char *str);
void				sa(t_stack *stack);
void				sb(t_stack *stack);
void				ss(t_stack *stack_a, t_stack *stack_b);
void				ra(t_stack **stack);
void				rb(t_stack **stack);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack);
void				rrb(t_stack **stack);
void				rrr(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ft_parsing(char **argv);
int					ifduplicated(t_stack *stack);
void				sort_three(t_stack **stack);
void				sort_two(t_stack *stack);
void				sort_five(t_stack **stack_a, t_stack **stack_b);
void				sort_four(t_stack **stack_a, t_stack **stack_b);
void				indexing(t_stack *stack);
void				range1(t_stack **stack_a, t_stack **stack_b);
void				ft_error(void);
int					lstsize(t_stack *stack);
void				ft_parsing_helper(char c);
void				sort_stack(t_stack **stack_a, t_stack **stack_b);
void				checkmax(long value, t_stack **stack, char **string);
void				switch_x(t_stack *stack);
void				rotate_x(t_stack **stack);
void				reverse_rot_x(t_stack **stack);

#endif