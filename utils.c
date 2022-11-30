/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:17:44 by phudyka           #+#    #+#             */
/*   Updated: 2022/11/24 17:19:15 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nbr(char c)
{
	return(c >= '0' && c <= '9');
}

int ft_sign(char c)
{
	return(c == '+' || c == '-');
}