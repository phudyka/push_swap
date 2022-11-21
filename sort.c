/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:39:36 by phudyka           #+#    #+#             */
/*   Updated: 2022/11/21 15:43:17 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	highest(t_stack *stack)
{
	
}

void	minisort(t_stack **stack_a)
{
	t_stack	*one;
	t_stack	*two;
	t_stack	*three;
	
	while (!ft_sorted(*stack_a))
	{
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

void	maxisort(t_stack **stack_a, t_stack **stack_b)
{
	presort(stack_a, stack_b);
	minisort(stack_a);
}