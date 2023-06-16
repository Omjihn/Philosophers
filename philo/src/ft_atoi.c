/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:02:16 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/16 10:54:25 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/philo.h"

static void	ft_overflow(int total, int add, t_vars *vars)
{
	int	temp;

	if (total == 0 && add == 0)
		return ;
	temp = (total * 10) + add;
	if (((temp - add) / 10) == total)
		return ;
	vars->error = 2;
	return ;
}

int	ft_atoi(const char *nptr, t_vars *vars)
{
	int	i;
	int	sign;
	int	result;

	sign = 1;
	i = 0;
	result = 0;
	while (nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		ft_overflow(result, nptr[i] - 48, vars);
		result *= 10;
		result += nptr[i] - 48;
		i++;
	}
	return (result * sign);
}
