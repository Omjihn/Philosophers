/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life_cycle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:44:05 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/19 17:51:31 by gbricot          ###   ########.fr       */
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
	philo->actual = 's';
	philo->nb_forks = 1;
	pthread_mutex_init(&philo->mutex, NULL);
	vars->philo_nb++;
	return (philo);
}

static void	ft_philo_eat(t_philo *philo, t_vars *vars)
{
	pthread_mutex_unlock(&philo->mutex);
	printf(MSG_EAT, vars->current_time - vars->base_time, philo->pos);
	philo->time_end_eat = vars->current_time + vars->time_to_eat;
	while (vars->current_time <= philo->time_end_eat && vars->is_end == 0)
	{
	}
	pthread_mutex_lock(&philo->mutex);
	pthread_mutex_lock(&vars->philos[philo->next_index]->mutex);
	vars->philos[philo->next_index]->nb_forks += 1;
	philo->nb_forks -= 1;
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&vars->philos[philo->next_index]->mutex);
	philo->time_to_die = vars->current_time + vars->time_to_die;
	if (philo->nb_eat != -1)
		philo->nb_eat++;
	if (philo->nb_eat == vars->nb_eat)
	{
		vars->nb_finish++;
		philo->actual = 'f';
	}
	else
		philo->actual = 'e';
}

static void	ft_steal_fork(t_philo *philo, t_vars *vars)
{
	if ((philo->index != philo->next_index) && vars->is_end == 0)
	{
		pthread_mutex_lock(&philo->mutex);
		vars->philos[philo->next_index]->nb_forks -= 1;
		philo->nb_forks += 1;
		pthread_mutex_unlock(&vars->philos[philo->next_index]->mutex);
		printf(MSG_FORK, vars->current_time - vars->base_time, philo->pos);
	}
}

static void	ft_philo_extend(t_vars *vars, t_philo *philo)
{
	if (philo->actual == 't' && vars->is_end == 0)
	{
		if (philo->nb_forks == 1)
		{
			pthread_mutex_lock(&vars->philos[philo->next_index]->mutex);
			if (vars->philos[philo->next_index]->nb_forks == 1)
				ft_steal_fork(philo, vars);
			pthread_mutex_unlock(&vars->philos[philo->next_index]->mutex);

		}
		if (philo->nb_forks == 2)
			ft_philo_eat(philo, vars);
	}
	if (philo->actual == 'e' && vars->is_end == 0)
	{
		printf(MSG_SLEEP, vars->current_time - vars->base_time, philo->pos);
		philo->time_end_sleep = vars->current_time + vars->time_to_sleep;
		philo->actual = 's';
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
		usleep(50);
	}
	vars->starting_block++;
	philo->time_to_die = vars->time_to_die + vars->current_time;
	while (philo->time_to_die > vars->current_time && vars->is_end == 0)
	{
		usleep(10);
		ft_philo_extend(vars, philo);
		if (philo->actual == 'f')
			return (NULL);
	}
	vars->is_end = 1;
	if (vars->msg_dead == 0)
		ft_life_cycle_extend(philo, vars);
	return (NULL);
}
