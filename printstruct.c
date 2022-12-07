/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstruct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:22:35 by phudyka           #+#    #+#             */
/*   Updated: 2022/12/07 11:41:32 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printstruct(t_stack *stack)
{
	ft_putnbr_fd(stack->cosby, 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(stack->costa, 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(stack->index, 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(stack->target, 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(stack->pos, 2);
	ft_putchar_fd('\n', 2);
	while (stack)
	{
		ft_putnbr_fd(stack->value, 2);
	ft_putchar_fd('\n', 2);
		stack = stack->next;
	}
}