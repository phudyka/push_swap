/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:07:01 by phudyka           #+#    #+#             */
/*   Updated: 2022/11/29 11:13:36 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	presort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	j;
	int	size;
	
	size = ft_stack_size(*stack_a);
	j = size;
	while (j && size > 5)
	{
		if ((*stack_a)->index > size / 2)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		j--;
	}
	i = 0;
	size = ft_stack_size(*stack_a);
	if (size <= 3)
		return;
	while (i < (size - 3))
	{
		pb(stack_a, stack_b);
		i++;
	}
}