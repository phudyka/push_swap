/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:38:36 by phudyka           #+#    #+#             */
/*   Updated: 2022/11/30 15:48:34 by phudyka          ###   ########.fr       */
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
		{
			ft_free(&stack_a);
			ft_error("Error! INPUT OUT OF INT RANGE");
		}
		if (i == 1)
			stack_a = ft_init_stack((int)nbr);
		else
			ft_add_end(&stack_a, ft_init_stack((int)nbr));
		i++;
	}
	return(stack_a);
}

t_stack *ft_init_stack(int val)
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
	return(stack);
}

void	ft_index(t_stack *stack_a, int size)
{
	unsigned int	flag;
	t_stack			*temp;
	
	temp = stack_a;
	while(stack_a)
	{
		flag = 0;
		while (stack_a)
		{
			if (temp->value > stack_a->value)
				flag++;
			temp = temp->next;
		}
		stack_a->index = size - flag;
		stack_a = stack_a->next;
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
		ft_error("Error! BAD ARGUMENTS.");
	if (!check_arg(argv))
		ft_error("Error! BAD ARGUMENTS.");
	if (ft_sorted(stack_a))
		return(EXIT_SUCCESS);
	stack_b = NULL;
	stack_a = ft_fill_stack(argc, argv);
	size = ft_stack_size(stack_a);
	ft_index(stack_a, size + 1);
	push_swap(&stack_a, &stack_b, size);
	ft_free(&stack_a);
	ft_free(&stack_b);
}
