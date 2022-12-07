/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:22:50 by phudyka           #+#    #+#             */
/*   Updated: 2022/12/06 11:37:18 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_exit(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || *stack_a)
		ft_free(stack_a);
	if (!stack_b || *stack_b)
		ft_free(stack_b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_free(t_stack **stack)
{
	t_stack	*temp;
	
	if (!stack || !*stack)
		return;
	while(*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}
