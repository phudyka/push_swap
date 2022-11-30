/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:54:39 by phudyka           #+#    #+#             */
/*   Updated: 2022/11/28 16:07:56 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **stack1, t_stack **stack2)
{
	t_stack *temp;

	if (*stack1 == NULL)
		return;
	temp = *stack1;
	*stack1 = (*stack1)->next;
	temp->next = NULL;
	ft_add_start(stack2, temp);
}

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}