/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:41:51 by phudyka           #+#    #+#             */
/*   Updated: 2022/11/28 10:52:17 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target(t_stack *stack_a, t_stack *stack_b)
{
	int	max;
	int	diff;
	t_stack			*tempa;
	
	max  = 0;
	tempa = stack_a;
	while (stack_b)
	{
		stack_a = tempa;
		diff = UINT_MAX;
		while (stack_a)
		{
			if (stack_a->index > max)
				max = stack_a->index;
			if (diff > stack_a->index - stack_b->index && stack_a->index > stack_b->index)
				{
					diff = stack_a->index - stack_b->index;
					stack_b->target = stack_a->pos;
				}
			stack_a = stack_a->next;
		}
	}
	if (stack_b->index > max)
	{
		while (stack_a)
		{
			if (stack_a->index < max)
			{
				max = stack_a->index;
				stack_b->target = stack_a->pos;
			}
			stack_a = stack_a->next;
		}
	}
}
