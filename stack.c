/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:41:27 by phudyka           #+#    #+#             */
/*   Updated: 2022/11/29 11:00:49 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_stack	*end(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return(stack);
}

t_stack	*before_end(t_stack *stack)
{
		while (stack && stack->next->next != NULL)
		stack = stack->next;
	return(stack);
}

void	ft_add_start(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	(*stack) = new;
}

void	ft_add_end(t_stack **stack, t_stack *new)
{
	t_stack	*last;
	
	if (!*stack)
	{
		*stack = new;
		return;
	}
	last = end(*stack);
	last->next = new;
}

int	ft_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return(size);
}
