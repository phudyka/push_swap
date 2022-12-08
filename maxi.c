/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:04:29 by phudyka           #+#    #+#             */
/*   Updated: 2022/12/08 17:56:28 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		steps(long costa, long cosby) //
{
	long	low;
	
	low = 0;
	while (costa != 0 || cosby != 0)
	{
		if (costa > 0 && cosby > 0)
		{
			low++;
			costa--;
			cosby--;
		}
		else if (costa < 0 && cosby < 0)
		{
			low++;
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

static void	cost(t_stack **stack_a, t_stack **stack_b)
{
	int		max_b;
	int		max_a;
	t_stack *tempa;
	t_stack	*tempb;

	tempa = *stack_a;
	tempb = *stack_b;
	max_b = ft_stack_size(tempb);
	max_a = ft_stack_size(tempa);
	while (tempb)
	{
		tempb->cosby = tempb->pos;
		if (tempb->pos > max_b / 2)
			tempb->cosby = (max_b - tempb->pos) * -1;
		tempb->costa = tempb->target;
		if (tempb->target > max_a / 2)
			tempb->costa = (max_a - tempb->target) * -1;
		tempb = tempb->next;
	}
}

static void	lowcost(t_stack **stack_a, t_stack **stack_b)
{
	int		low;
	int		costa;
	int		cosby;
	t_stack *temp;
	
	low = INT_MAX;
	temp = *stack_b;
	while (temp)
	{
		if (steps(temp->costa, temp->cosby) < low)
		{
			low = steps(temp->costa, temp->cosby);
			costa = temp->costa;
			cosby = temp->cosby;
		}
		temp = temp->next;
	}
	master_rotation(stack_a, stack_b, costa, cosby);
}

static void	ft_done(t_stack **stack_a)
{
	int	low;
	int	size;
	
	low = lowest(stack_a);
	size = ft_stack_size(*stack_a);
	if (low > size /2)
	{
		while (low < size)
		{
			rra(stack_a);
			low++;
		}
	}
	else
	{
		while (low > 0)
		{
			ra(stack_a);
			low--;
		}
	}
}

void	maxisort(t_stack **stack_a, t_stack **stack_b)
{
	presort(stack_a, stack_b);
	minisort(stack_a);
	while (*stack_b)
	{
		target(stack_a, stack_b);
		cost(stack_a, stack_b);
		lowcost(stack_a, stack_b);
	}
	if (!ft_sorted(*stack_a))
		ft_done(stack_a);
}
