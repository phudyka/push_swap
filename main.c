/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:43:54 by phudyka           #+#    #+#             */
/*   Updated: 2022/12/12 15:43:56 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack(int argc, char **argv)
{
	int			i;
	long		nbr;
	t_stack		*stack_a;

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
		i++;
	}
	return (stack_a);
}

void	ft_index(t_stack *stack_a, int size)
{
	int		val;
	t_stack	*max;
	t_stack	*temp;

	while (--size > 0)
	{
		val = INT_MIN;
		max = NULL;
		temp = stack_a;
		while (temp)
		{
			if (temp->value == INT_MIN && temp->index == 0)
				temp->index = 1;
			if (temp->value > val && temp->index == 0)
			{
				val = temp->value;
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

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2 && !ft_sorted(*stack_a))
		sa(stack_a);
	else if (size == 3)
		mini(stack_a);
	else if (size > 3 && !ft_sorted(*stack_a))
		maxi(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	if (argc < 2)
		return (0);
	if (!check_input(argv))
		ft_exit(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_stack(argc, argv);
	size = ft_stack_size(stack_a);
	ft_index(stack_a, size + 1);
	push_swap(&stack_a, &stack_b, size);
	ft_free(&stack_a);
	ft_free(&stack_b);
	return (0);
}
