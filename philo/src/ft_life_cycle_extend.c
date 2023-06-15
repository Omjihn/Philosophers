/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life_cycle_extend.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:30:39 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/15 17:32:40 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_life_cycle_extend(t_philo *philo, t_vars *vars)
{
	if (vars->is_end == 0)
	{
		pthread_mutex_lock(&vars->mutex);
		vars->is_end = 1;
		pthread_mutex_unlock(&vars->mutex);
		printf(DEAD_MSG, vars->current_time - vars->base_time, philo->pos);
	}
}
