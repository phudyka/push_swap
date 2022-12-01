/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:04:08 by phudyka           #+#    #+#             */
/*   Updated: 2022/12/01 11:57:18 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return(0);
		stack = stack->next;
	}
	return(1);
}

void    pos(t_stack *stack)
{
	unsigned int	i;
	unsigned int	size;
	
	i = 0;
	size = (unsigned int)ft_stack_size(stack);
	while (i < size)
	{
		stack->pos = i;
		stack = stack->next;
		i++;
	}
}

static int ft_max(t_stack *stack_a)
{
	int max;
	
	max = stack_a->index;
	while (stack_a)
	{
		if (stack_a->index > max)
			max = stack_a->index;
		stack_a = stack_a->next;
	}
	return (max);
}

void	minisort(t_stack **stack_a)
{
	int	max;

	if (ft_sorted(*stack_a))
		return;
	max = ft_max(*stack_a);
	if ((*stack_a)->index == max)
		ra(stack_a);
	else if ((*stack_a)->next->index == max)
		rra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}
