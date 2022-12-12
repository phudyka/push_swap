/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:47:41 by phudyka           #+#    #+#             */
/*   Updated: 2022/12/12 15:36:25 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_stack
{
	int				pos;
	int				value;
	int				index;
	int				costa;
	int				cosby;
	int				target;
	struct s_stack	*next;
}	t_stack;

int		check_input(char **argv);
long	ft_atoi(const char *str);
void	ft_putstr(char *str);
int		ft_nbr(char nb);
int		ft_sign(char s);
void	ft_exit(t_stack **stack_a, t_stack **stack_b);
t_stack	*fill_stack(int argc, char **argv);
t_stack	*ft_init_stack(int value);
void	ft_add_end(t_stack **stack, t_stack *new);
t_stack	*end(t_stack *stack);
t_stack	*before_end(t_stack *stack);
int		ft_stack_size(t_stack	*stack);
void	ft_free(t_stack **stack);
void	ft_index(t_stack *stack_a, int size);
int		ft_sorted(t_stack *stack);
void	mini(t_stack **stack);
void	maxi(t_stack **stack_a, t_stack **stack_b);
void	target(t_stack **stack_a, t_stack **stack_b);
int		low(t_stack **stack);
void	get_position(t_stack **stack);
void	cost(t_stack **stack_a, t_stack **stack_b);
void	lowcost(t_stack **stack_a, t_stack **stack_b);
int		ft_abs(int nbr);
void	master_rotation(t_stack **a, t_stack **b, int cost_a, int cost_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);

#endif