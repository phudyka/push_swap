/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:47:14 by phudyka           #+#    #+#             */
/*   Updated: 2022/11/28 16:05:06 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*temp;

	if (stack == NULL || *stack == NULL)
		return;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	ft_add_end(stack, temp);
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}
void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}