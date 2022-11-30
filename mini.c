/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:04:08 by phudyka           #+#    #+#             */
/*   Updated: 2022/11/29 10:57:54 by phudyka          ###   ########.fr       */
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

void	minisort(t_stack **stack_a)
{
	t_stack	*one;
	t_stack	*two;
	t_stack	*three;
	
	while (!ft_sorted(*stack_a))
	{
		one = (*stack_a);
		two = (*stack_a)->next;
		three = (*stack_a)->next->next;
		if (one->index > two->index && one->index > three->index)
			ra(stack_a);
		else if (two->index > one->index && two->index > three->index)
			rra(stack_a);
		else if (one->index > two->index)
			sa(stack_a);
		else
			ft_error("Error!: MINISORT FAILED.");	
	}
}
