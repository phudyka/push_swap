/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:05:49 by phudyka           #+#    #+#             */
/*   Updated: 2022/11/21 15:22:16 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <errno.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				pos;
	int 			index;
    int				value;
	int				costa;
	int 			cosby;
	int				target;
	struct s_stack	*next;
}				t_stack;

void	ft_error(char *msg);
void	ft_exit(char *msg, t_stack *stack_a, t_stack *stack_b);
int		ft_input(char **argv);
int		check_dup(char **argv);
int		check_arg(char *argv);
int		ft_stack_size(t_stack *stack);
t_stack	*ft_fill_stack(int argc, char **argv);
void	ft_add_end(t_stack **stack, t_stack *new);
t_stack *ft_new_stack(int val);
t_stack	*end(t_stack *stack);
t_stack	*before_end(t_stack *stack);
void    ft_index(t_stack *stack_a, int argc);
void	push_swap(t_stack *stack_a, t_stack *stack_b, int size);
void	swap(t_stack *stack);
void    minisort(t_stack **stack_a);
void	rotate(t_stack **stack);
void	maxisort(t_stack **stack_a, t_stack ** stack_b);
void	presort(t_stack **stack_a, t_stack **stack_b);
void    push(t_stack **stack1, t_stack **stack2);
void    target(t_stack **stack_a, t_stack **stack_b);
void    cost(t_stack **stack_a, t_stack **stack_b);
int		get_target(t_stack **stack_a, int index, int max, int target);
void    lowcost(t_stack **stack_a, t_stack **stack_b);
void    pos(t_stack **stack);
void	master_rotation(t_stack **stack_a, t_stack  **stack_b, int costa, int cosby);
void	double_rotation(t_stack **stack_a, t_stack **stack_b, int *costa, int *cosby);
void	double_reverse_rotation(t_stack **stack_a, t_stack **stack_b, int *costa, int *cosby);
void	rotation_a(t_stack **stack_a, int *costa);
void	rotation_b(t_stack **stack_b, int *cosby);
void	reverse(t_stack **stack);
int		ft_sorted(t_stack *stack);
void	ft_done(t_stack **stack_a);
int		lowest(t_stack **stack_a);
void	ft_free(t_stack **stack);
void	pa(t_stack **stack_b, t_stack **stack_a);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_a);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
#endif