/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life_cycle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:44:05 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/15 15:11:05 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo	*ft_init_philo(t_vars *vars)
{
	t_philo	*philo;

	philo = vars->philos[vars->philo_nb];
	philo->index = vars->philo_nb;
	if (philo->index == vars->nb_forks - 1)
		philo->next_index = 0;
	else
		philo->next_index = philo->index + 1;
	if (vars->nb_forks == 1)
		philo->next_index = philo->index;
	philo->pos = philo->index + 1;
	philo->nb_eat = vars->nb_eat;
	philo->actual = 's';
	philo->nb_forks = 1;
	pthread_mutex_lock(&vars->mutex);
	vars->philo_nb++;
	pthread_mutex_unlock(&vars->mutex);
	return (philo);
}

static void	ft_philo_eat(t_philo *philo, t_vars *vars)
{
	printf(MSG_EAT, vars->current_time - vars->base_time, philo->pos);
	philo->time_end_eat = vars->current_time + vars->time_to_eat;
	while (vars->current_time < philo->time_end_eat && vars->is_end == 0)
	{
	}
	pthread_mutex_lock(&vars->mutex);
	vars->philos[philo->next_index]->nb_forks++;
	philo->nb_forks--;
	pthread_mutex_unlock(&vars->mutex);
	philo->time_to_die = vars->current_time + vars->time_to_die;
	philo->actual = 'e';
}

static void	ft_steal_fork(t_philo *philo, t_vars *vars)
{
	if (vars->philos[philo->next_index]->nb_forks == 1
		&& (philo->index != philo->next_index)
		&& vars->is_end == 0)
	{
		pthread_mutex_lock(&vars->mutex);
		vars->philos[philo->next_index]->nb_forks--;
		philo->nb_forks++;
		pthread_mutex_unlock(&vars->mutex);
		printf(MSG_FORK, vars->current_time - vars->base_time, philo->pos);
	}
}

static void	ft_philo_extend(t_vars *vars, t_philo *philo)
{
	if (philo->nb_forks == 2 && philo->actual == 't' && vars->is_end == 0)
		ft_philo_eat(philo, vars);
	else if (philo->actual == 't' && philo->nb_forks == 1
		&& vars->is_end == 0)
		ft_steal_fork(philo, vars);
	else if (philo->actual == 'e' && vars->is_end == 0)
	{
		printf(MSG_SLEEP, vars->current_time - vars->base_time, philo->pos);
		philo->time_end_sleep = vars->current_time + vars->time_to_sleep;
		pthread_mutex_lock(&vars->mutex);
		philo->actual = 's';
		pthread_mutex_unlock(&vars->mutex);
	}
	else if (philo->actual == 's'
		&& vars->current_time >= philo->time_end_sleep
		&& vars->is_end == 0)
	{
		printf(MSG_THINK, vars->current_time - vars->base_time, philo->pos);
		philo->actual = 't';
	}
}

void	*ft_philosopher(void *arg)
{
	t_vars	*vars;
	t_philo	*philo;

	vars = (t_vars *) arg;
	philo = ft_init_philo(vars);
	while (philo->pos != vars->starting_block)
	{
	}
	pthread_mutex_lock(&vars->mutex);
	vars->starting_block++;
	pthread_mutex_unlock(&vars->mutex);
	philo->time_to_die = vars->time_to_die + vars->current_time;
	while (philo->time_to_die > vars->current_time && vars->is_end == 0)
	{
		ft_philo_extend(vars, philo);
	}
	if (vars->is_end == 0)
	{
		pthread_mutex_lock(&vars->mutex);
		vars->is_end = 1;
		pthread_mutex_unlock(&vars->mutex);
		printf(DEAD_MSG, vars->current_time - vars->base_time, philo->pos);
	}
	return (NULL);
}
