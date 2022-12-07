/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:05:49 by phudyka           #+#    #+#             */
/*   Updated: 2022/12/07 11:27:10 by phudyka          ###   ########.fr       */
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
	int	pos;
    int	value;
	int	index;
	int	costa;
	int	cosby;
	int	target;
	struct s_stack	*next;
}				t_stack;

int		ft_error(void);
void	ft_exit(t_stack **stack_a, t_stack **stack_b);
int		check_arg(char **argv);
int		ft_nbr(char c);
int		ft_sign(char c);
int		ft_stack_size(t_stack *stack);
t_stack	*ft_fill_stack(int argc, char **argv);
void	ft_add_end(t_stack **stack, t_stack *new);
t_stack *ft_init_stack(int val);
t_stack	*end(t_stack *stack);
t_stack	*before_end(t_stack *stack);
void    ft_index(t_stack *stack_a, int size);
void	push_swap(t_stack **stack_a, t_stack **stack_b, int size);
void    minisort(t_stack **stack_a);
void	maxisort(t_stack **stack_a, t_stack ** stack_b);
void	presort(t_stack **stack_a, t_stack **stack_b);
void	target(t_stack **stack_a, t_stack **stack_b);
void    pos(t_stack *stack);
void	master_rotation(t_stack **stack_a, t_stack  **stack_b, int costa, int cosby);
int		ft_sorted(t_stack *stack);
int		lowest(t_stack **stack_a);
void	ft_free(t_stack **stack);
void	pa(t_stack **stack_b, t_stack **stack_a);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_a);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	printstruct(t_stack *stack);
#endif
