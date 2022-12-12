/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:43:15 by phudyka           #+#    #+#             */
/*   Updated: 2022/12/12 15:43:25 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = ft_stack_size(tmp_a);
	size_b = ft_stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cosby = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cosby = (size_b - tmp_b->pos) * -1;
		tmp_b->costa = tmp_b->target;
		if (tmp_b->target > size_a / 2)
			tmp_b->costa = (size_a - tmp_b->target) * -1;
		tmp_b = tmp_b->next;
	}
}

void	lowcost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (ft_abs(tmp->costa) + ft_abs(tmp->cosby) < ft_abs(cheapest))
		{
			cheapest = ft_abs(tmp->cosby) + ft_abs(tmp->costa);
			cost_a = tmp->costa;
			cost_b = tmp->cosby;
		}
		tmp = tmp->next;
	}
	master_rotation(stack_a, stack_b, cost_a, cost_b);
}