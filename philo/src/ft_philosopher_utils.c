/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:27:50 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/20 17:51:00 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_is_dead(t_vars *vars, t_philo *philo)
{
	pthread_mutex_lock(&vars->mutex);
	if (ft_gct() > philo->time_to_die && vars->is_end == 0)
	{
		vars->is_end = 1;
		printf(RED DEAD WTE, ft_get(vars), philo->pos);
	}
	pthread_mutex_unlock(&vars->mutex);
}

void	ft_steal_fork(t_vars *vars, t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	if (philo->nb_forks == 1 && vars->is_end == 0 && vars->nb_forks > 1)
	{
		pthread_mutex_unlock(&philo->mutex);
		pthread_mutex_lock(&vars->philos[philo->next_index]->mutex);
		if (vars->philos[philo->next_index]->nb_forks == 1)
		{
			vars->philos[philo->next_index]->nb_forks--;
			pthread_mutex_unlock(&vars->philos[philo->next_index]->mutex);
			pthread_mutex_lock(&philo->mutex);
			philo->nb_forks++;
			pthread_mutex_unlock(&philo->mutex);
			printf(MSG_FORK, ft_get(vars), philo->pos);
		}
	}
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&vars->philos[philo->next_index]->mutex);
}

void	ft_eat(t_vars *vars, t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	if (philo->nb_forks == 2 && vars->is_end == 0)
	{
		pthread_mutex_unlock(&philo->mutex);
		philo->time_end_eat = ft_gct() + vars->time_to_eat;
		printf(MSG_EAT, ft_get(vars), philo->pos);
		philo->actual = 'e';
		philo->time_to_die = ft_gct() + vars->time_to_die;
	}
	pthread_mutex_unlock(&philo->mutex);
}

void	ft_think(t_vars *vars, t_philo *philo)
{
	if (ft_gct() >= philo->time_end_sleep && vars->is_end == 0)
	{
		printf(MSG_THINK, ft_get(vars), philo->pos);
		philo->actual = 't';
	}
}

void	ft_sleep(t_vars *vars, t_philo *philo)
{
	if (ft_gct() >= philo->time_end_eat && vars->is_end == 0)
	{
		printf(MSG_SLEEP, ft_get(vars), philo->pos);
		philo->actual = 's';
		if (philo->nb_eat >= 0)
			philo->nb_eat++;
		if (philo->nb_eat == vars->nb_eat)
			vars->nb_finish++;
		pthread_mutex_lock(&vars->philos[philo->next_index]->mutex);
		pthread_mutex_lock(&philo->mutex);
		philo->nb_forks--;
		vars->philos[philo->next_index]->nb_forks++;
		pthread_mutex_unlock(&philo->mutex);
		pthread_mutex_unlock(&vars->philos[philo->next_index]->mutex);
		philo->time_end_sleep = ft_gct() + vars->time_to_sleep;
	}
}
