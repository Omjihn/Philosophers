/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:53:32 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/21 10:58:39 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo	*ft_init_philo(t_vars *vars)
{
	t_philo	*philo;

	philo = vars->philos[vars->philo_nb];
	philo->index = vars->philo_nb;
	philo->next_index = philo->index;
	if (philo->index == 0)
		philo->prev_index = vars->nb_forks - 1;
	else
		philo->prev_index = philo->index - 1;
	if (vars->nb_forks == 1)
		philo->next_index = philo->index;
	philo->pos = philo->index + 1;
	philo->actual = 's';
	vars->philo_nb++;
	return (philo);
}

void	*ft_philosopher(void *arg)
{
	t_vars	*vars;
	t_philo	*philo;

	vars = (t_vars *) arg;
	philo = ft_init_philo(vars);
	while (vars->base_time == 0)
	{
	}
	philo->time_to_die = ft_gct() + vars->time_to_die;
	while (vars->is_end == 0 && vars->nb_finish != vars->nb_forks)
	{
		usleep(20);
		ft_is_dead(vars, philo);
		if (philo->actual == 's')
			ft_think(vars, philo);
		if (philo->actual == 't')
		{
			ft_steal_fork(vars, philo);
			ft_eat(vars, philo);
		}
		if (philo->actual == 'e')
			ft_sleep(vars, philo);
	}
	vars->is_end = 1;
	return (NULL);
}
