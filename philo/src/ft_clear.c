/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:17:12 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/21 12:39:52 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_all(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->philos[i])
	{
		free(vars->philos[i]);
		free(vars->fork[i]);
		i++;
	}
	free (vars->philos);
	free (vars->fork);
	free (vars);
}

void	ft_quit_all_threads(t_vars *vars)
{
	int	i;

	pthread_mutex_destroy(&vars->mutex);
	i = 0;
	while (vars->philos[i])
	{
		pthread_mutex_destroy(&vars->fork[i]->mutex);
		pthread_detach(vars->philos[i]->thread);
		i++;
	}
}
