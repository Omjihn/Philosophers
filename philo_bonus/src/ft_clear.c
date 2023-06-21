/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:54:24 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/21 17:58:03 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_free_all(t_vars *vars)
{
	int	i;
	i = 0;
	while (vars->philos[i])
	{
		free(vars->philos[i]);
		i++;
	}
	free (vars->philos);
	free (vars->pid);
	free (vars);
}
