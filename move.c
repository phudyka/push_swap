/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:39:07 by phudyka           #+#    #+#             */
/*   Updated: 2022/11/28 10:54:49 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotation_a(t_stack **stack_a, long *costa)
{
	if ((*costa) > 0)
	{
		ra(stack_a);
		(*costa)++;
	}
	else if ((*costa) < 0)
	{
		rra(stack_a);
		(*costa)--;
	}
}

static void	rotation_b(t_stack **stack_b, long *cosby)
{
	if ((*cosby) > 0)
	{
		rb(stack_b);
		(*cosby)++;
	}
	else if ((*cosby) < 0)
	{
		rrb(stack_b);
		(*cosby)--;
	}
}

static void	double_rotation(t_stack **stack_a, t_stack **stack_b, long *costa, long *cosby)
{
	rr(stack_a, stack_b);
	(*costa)--;
	(*cosby)--;
}

static void	double_reverse_rotation(t_stack **stack_a, t_stack **stack_b, long *costa, long *cosby)
{
	rrr(stack_a, stack_b);
	(*costa)++;
	(*cosby)++;
}

void	master_rotation(t_stack **stack_a, t_stack  **stack_b, long costa, long cosby)
{
	while (costa != 0 || cosby != 0)
	{
		if (costa > 0 && cosby > 0)
			double_rotation(stack_a, stack_b, &costa, &cosby);
		else if (costa < 0 && cosby < 0)
			double_reverse_rotation(stack_a, stack_b, &costa, &cosby);
		else if (costa != 0)
			rotation_a(stack_a, &costa);
		else if (cosby < 0)
			rotation_b(stack_b, &cosby);
	}
}