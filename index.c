/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:35:30 by phudyka           #+#    #+#             */
/*   Updated: 2022/12/08 16:18:07 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lowest(t_stack **stack_a)
{
	int		index;
	int		position;
	t_stack *temp;
	
	pos(*stack_a);
	temp = *stack_a;
	position = temp->pos;
	while(temp)
	{
		if (temp->index < index)
		{
			index = temp->index;
			position = temp->pos;
		}
		temp = temp->next;
	}
	return (position);
}