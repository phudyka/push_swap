/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:38:36 by phudyka           #+#    #+#             */
/*   Updated: 2022/12/06 11:1 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_fill_stack(int argc, char **argv)
{
	int		i;
	long	nbr;
	t_stack	*stack_a;
	
	i = 1;
	nbr = 0;
	stack_a = NULL;
	while (i < argc)
	{
		nbr = ft_atoi(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			ft_exit(&stack_a, NULL);
		if (i == 1)
			stack_a = ft_init_stack((int)nbr);
		else
			ft_add_end(&stack_a, ft_init_stack((int)nbr));
		printstruct(stack_a);
		i++;
	}
	return(stack_a);
}

t_stack *ft_init_stack(int val) // oui
{
	t_stack	*stack;
	
	stack = malloc(sizeof(*stack));
	if (!stack)
		return(NULL);
	stack->value = val;
	stack->costa = -1;
	stack->cosby = -1;
	stack->index = 0;
	stack->pos = 0;
	stack->target = 0;
	stack->next = NULL;
	return (stack);
}

void	ft_index(t_stack *stack_a, int size)
{
	t_stack	*max;
	t_stack	*temp;
	int		value;
	
	while (--size > 0)
	{
		max = NULL;
		temp = stack_a;
		value = INT_MIN;
		while (temp)
		{
			if (temp->value == INT_MIN && temp->index == 0)
				temp->index = 1;
			if (temp->value > value && temp->index == 0)
			{
				value = temp->value;
				max = temp;
				temp = stack_a;
			}
			else
				temp = temp->next;
		}
		if (max != NULL)
			max->index = size;
	}
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2 && !ft_sorted(*stack_a))
		sa(stack_a);
	else if (size == 3)
		minisort(stack_a);
	else if (size > 3 && !ft_sorted(*stack_a))
		maxisort(stack_a, stack_b);
}

int main(int argc, char **argv)
{
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;
	
	if (argc < 2)
		return (0);
	if (check_arg(argv) == 1)
		ft_exit(NULL, NULL);
	stack_b = NULL;
	stack_a = ft_fill_stack(argc, argv);
	size = ft_stack_size(stack_a);
	ft_index(stack_a, size);
	push_swap(&stack_a, &stack_b, size + 1);
	ft_free(&stack_a);
	ft_free(&stack_b);
}
