/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:22:50 by phudyka           #+#    #+#             */
/*   Updated: 2022/11/21 15:25:33 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	return(EXIT_FAILURE);	
}

void	ft_exit(char *msg, t_stack *stack_a, t_stack *stack_b)
{
	ft_free(stack_a);
	ft_free(stack_b);
	return
}

void	ft_free(t_stack **stack)
{
	
}