/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:38:36 by phudyka           #+#    #+#             */
/*   Updated: 2022/11/21 15:28:22 by phudyka          ###   ########.fr       */
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
			ft_exit("Error!: OUT OF INT RANGE", &stack_a, NULL);
		if (i == 1)
			stack_a = ft_new_stack((int)nbr);
		else
			ft_add_end(&stack_a, ft_new_stack((int)nbr));
		i++;
	}
	return (stack_a);
}

void	push_swap(t_stack *stack_a, t_stack *stack_b, int size)
{
	if (size == 2 && !ft_sorted(stack_a))
		ra(stack_a);
	else if (size == 3 && !ft_sorted(stack_a))
		minisort(stack_a);
	if (size > 3 && !ft_sorted(stack_a))
		maxisort(stack_a, stack_b);
}

int main(int argc, char **argv)
{
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;
	
	if (argc < 2)
		ft_error("Error! BAD ARGUMENTS");
	if (ft_sorted(stack_a))
		return(EXIT_SUCCESS);
	stack_b = NULL;
	stack_a = ft_fill_stack(argc, argv);
	size = ft_stack_size(stack_a);
	push_swap(stack_a, stack_b, size);
	ft_free(stack_a);
	ft_free(stack_b);
}