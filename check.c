/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:24:03 by phudyka           #+#    #+#             */
/*   Updated: 2022/11/24 17:30:33 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_input(char *argv)
{
	int	i;

	i = 0;
	if (ft_sign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && ft_nbr(argv[i]))
		i++;
	if (argv[i] != '\0' && !ft_nbr(argv[i]))
		return (0);
	return (1);
}

static int ft_nbcmp(const char *nb1, const char *nb2)
{
	int	i;
	int	j;
	
	i = 0;
	j = i;
	if (nb1[i] == '+')
	{
		if (nb2[j] != '+')
			i++;
	}
	else
	{
		if(nb2[j] == '+')
			j++;
	}
	while (nb1[i] && nb2[j] && nb1[i] == nb2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)nb1[i] - (unsigned char)nb2[j]);
}

static int	check_dup(char **argv)
{
	int	i;
	int	j;
	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != 1 && ft_nbcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int zero(char *argv)
{
	int	i;

	i = 0;
	if (ft_sign(argv[i]))
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return(0);
	return(1);
}

int		check_arg(char **argv)
{
	int	i;
	int z;
	
	i = 1;
	z = 0;
	while (argv[i])
	{
		if (!ft_input(argv[i]))
			return(0);
		z += zero(argv[i]);
		i++;
	}
	if (z > 1)
		return(0);
	if (check_dup(argv))
		return(0);
	return(1);
}