/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:59:18 by phudyka           #+#    #+#             */
/*   Updated: 2022/12/05 16:06:18 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;
	t_stack	*prev;

	last = end(*stack);
	prev = before_end(*stack);
	temp = *stack;
	*stack = last;
	(*stack)->next = temp;
	prev->next = NULL;
}

void	rra(t_stack **stack_a)
{
	reverse(stack_a);
	ft_putstr_fd("rra\n", 1);
}
void	rrb(t_stack **stack_b)
{
	reverse(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse(stack_a);
	reverse(stack_b);
	ft_putstr_fd("rrr\n", 1);
}