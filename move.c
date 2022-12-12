/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:44:36 by phudyka           #+#    #+#             */
/*   Updated: 2022/12/12 15:45:03 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	double_rotation(t_stack **stack_a, t_stack **stack_b, int *costa, int *cosby)
{
	while (*costa > 0 && *cosby > 0)
	{
		(*costa)--;
		(*cosby)--;
		rr(stack_a, stack_b);
	}
}

static void	double_reverse_rotation(t_stack **stack_a, t_stack **stack_b,
												int *costa, int *cosby)
{
	while (*costa < 0 && *cosby < 0)
	{
		(*costa)++;
		(*cosby)++;
		rrr(stack_a, stack_b);
	}
}

static void	rotation_a(t_stack **stack_a, int *costa)
{
	while (*costa)
	{
		if (*costa > 0)
		{
			ra(stack_a);
			(*costa)--;
		}
		else if (*costa < 0)
		{
			rra(stack_a);
			(*costa)++;
		}
	}
}

static void	rotation_b(t_stack **stack_b, int *cosby)
{
	while (*cosby)
	{
		if (*cosby > 0)
		{
			rb(stack_b);
			(*cosby)--;
		}
		else if (*cosby < 0)
		{
			rrb(stack_b);
			(*cosby)++;
		}
	}
}

void	master_rotation(t_stack **stack_a, t_stack **stack_b, int costa, int cosby)
{
	if (costa > 0 && cosby > 0)
		double_rotation(stack_a, stack_b, &costa, &cosby);
	else if (costa < 0 && cosby < 0)
		double_reverse_rotation(stack_a, stack_b, &costa, &cosby);
	rotation_a(stack_a, &costa);
	rotation_b(stack_b, &cosby);
	pa(stack_a, stack_b);
}
