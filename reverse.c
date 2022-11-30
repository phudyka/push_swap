/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:59:18 by phudyka           #+#    #+#             */
/*   Updated: 2022/11/28 15:15:01 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse(t_stack **stack)
{
	t_stack	*temp;

	if (stack == NULL || *stack == NULL)
		return;
	temp = *stack;
	if (temp->next == NULL)
		return;
	while (temp->next->next != NULL)
		temp = temp->next;
	ft_add_start(stack, temp->next);
	temp->next = NULL;
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