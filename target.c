/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:41:51 by phudyka           #+#    #+#             */
/*   Updated: 2022/12/05 12:09:14 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_target(t_stack **stack_a, int b, int target, int pos)
{
	t_stack *tempa;
	
	tempa = *stack_a;
	while (tempa)
	{
		if (tempa->index > b && tempa->index < target)
		{
			target = tempa->index;
			pos = tempa->pos;
		}
		tempa = tempa->next;
	}
	if (target != INT_MAX)
		return(pos);
	tempa = *stack_a;
	while (tempa)
	{
		if (tempa->index < target)
		{
			target = tempa->index;
			pos = tempa->pos;
		}
		tempa = tempa->next;
	}
	return(pos);
}

void	target(t_stack **stack_a, t_stack **stack_b)
{
	int		targ;
	t_stack *tempb;
	
	tempb = *stack_b;
	pos(*stack_a);
	pos(*stack_b);
	targ = 0;
	while (tempb)
	{
		targ = get_target(stack_a, tempb->index, INT_MAX, targ);
		tempb->target = targ;
		tempb = tempb->next;
	}
}