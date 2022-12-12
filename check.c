/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:42:48 by phudyka           #+#    #+#             */
/*   Updated: 2022/12/12 15:43:07 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_input(char *av)
{
	int	i;

	i = 0;
	if (ft_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && ft_nbr(av[i]))
		i++;
	if (av[i] != '\0' && !ft_nbr(av[i]))
		return (0);
	return (1);
}

static int	nb_cmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

static int	check_dup(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && nb_cmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_zero(char *av)
{
	int	i;

	i = 0;
	if (ft_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

int	check_input(char **argv)
{
	int	i;
	int	z;

	z = 0;
	i = 1;
	while (argv[i])
	{
		if (!ft_input(argv[i]))
			return (0);
		z += ft_zero(argv[i]);
		i++;
	}
	if (z > 1)
		return (0);
	if (check_dup(argv))
		return (0);
	return (1);
}
