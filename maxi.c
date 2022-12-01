/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:04:29 by phudyka           #+#    #+#             */
/*   Updated: 2022/12/01 11:48:51 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		steps(long costa, long cosby)
{
	long	low;
	
	low = 0;
	while (costa != 0|| cosby != 0)
	{
		if (costa > 0 && cosby > 0)
		{
			low++;
			costa--;
			cosby--;
		}
		else if (costa < 0 && cosby < 0)
		{
			low--;
			costa++;
			cosby++;
		}
		else
		{
			low += (ft_absol(costa) + ft_absol(cosby));
			costa = 0;
			cosby = 0;
		}
	}
	return(low);
}

static void	cost(t_stack *stack_a, t_stack *stack_b)
{
	int	max_b;
	int	max_a;

	max_b = ft_stack_size(stack_b);
	max_a = ft_stack_size(stack_a);
	while (stack_b)
	{
		if (max_b - stack_b->pos  < stack_b->pos)
		{
			stack_b->cosby = max_b - stack_b->cosby;
			stack_b->cosby = -stack_b->cosby;
		}	
		else
			stack_b->cosby = stack_b->pos;
		if (max_a - stack_b->target < stack_b->target)
		{
			stack_b->costa = max_a - stack_b->target;
			stack_b->costa = -stack_b->costa;
		}	
		else
			stack_b->costa = stack_b->target;
		stack_b = stack_b->next;
	}
}

static void	lowcost(t_stack **stack_a, t_stack **stack_b)
{
	long	low;
	int		costa;
	int		cosby;
	t_stack *temp;
	
	low = LONG_MAX;
	temp = *stack_b;
	while (temp)
	{
		if (steps(temp->costa, temp->cosby) < low)
		{
			costa = temp->costa;
			cosby = temp->cosby;
			low = steps(temp->costa, temp->cosby);
		}
		temp = temp->next;
	}
	master_rotation(stack_a, stack_b, costa, cosby);
}

static void	ft_done(t_stack **stack_a)
{
	long	low;
	long	size;
	t_stack	*temp;

	pos(*stack_a);
	temp = *stack_a;
	low = 0;
	while (temp)
	{
		if (temp->index == 1)
		{
			low = temp->index;
			break;
		}
		temp = temp->next;
	}
	size = (long)ft_stack_size(*stack_a);
	if (size - low < low)
	{
		low -= size;
		low = -low;
	}
	master_rotation(stack_a, NULL, low, 0);
}

void	maxisort(t_stack **stack_a, t_stack **stack_b)
{
	presort(stack_a, stack_b);
	minisort(stack_a);
	while (*stack_b)
	{
		pos(*stack_a);
		target(*stack_a, *stack_b);
		cost(*stack_a, *stack_b);
		lowcost(stack_a, stack_b);
		pa(stack_b, stack_a);
		if (!(*stack_b))
			ft_done(stack_a);
	}
}