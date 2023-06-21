/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:27:50 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/21 15:36:30 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_is_dead(t_vars *vars, t_philo *philo)
{
	if (ft_gct() > philo->time_to_die && vars->is_end == 0)
	{
		vars->is_end = 1;
		printf(RED DEAD WTE, ft_get(vars), philo->pos);
	}
}

void	ft_steal_fork(t_vars *vars, t_philo *philo)
{
	if (vars->nb_forks == 1)
		return ;
	pthread_mutex_lock(&vars->fork[philo->prev_index]->mutex);
	if (vars->fork[philo->prev_index]->nb == 1 && vars->is_end == 0)
	{
		vars->fork[philo->prev_index]->nb--;
		philo->nb_forks += 1;
		printf(MSG_FORK, ft_get(vars), philo->pos);
	}
	pthread_mutex_unlock(&vars->fork[philo->prev_index]->mutex);
	pthread_mutex_lock(&vars->fork[philo->next_index]->mutex);
	if (vars->fork[philo->next_index]->nb == 1 && vars->is_end == 0)
	{
		vars->fork[philo->next_index]->nb--;
		philo->nb_forks += 1;
		printf(MSG_FORK, ft_get(vars), philo->pos);
	}
	pthread_mutex_unlock(&vars->fork[philo->next_index]->mutex);
}

void	ft_eat(t_vars *vars, t_philo *philo)
{
	if (philo->nb_forks == 2 && vars->is_end == 0)
	{
		philo->time_end_eat = ft_gct() + vars->time_to_eat;
		philo->time_to_die = ft_gct() + vars->time_to_die;
		printf(MSG_EAT, ft_get(vars), philo->pos);
		philo->actual = 'e';
	}
}

void	ft_think(t_vars *vars, t_philo *philo)
{
	if (ft_gct() >= philo->time_end_sleep && vars->is_end == 0)
	{
		pthread_mutex_unlock(&vars->mutex);
		printf(MSG_THINK, ft_get(vars), philo->pos);
		philo->actual = 't';
	}
}

void	ft_sleep(t_vars *vars, t_philo *philo)
{
	if (ft_gct() >= philo->time_end_eat && vars->is_end == 0)
	{
		printf(MSG_SLEEP, ft_get(vars), philo->pos);
		pthread_mutex_lock(&vars->fork[philo->next_index]->mutex);
		pthread_mutex_lock(&vars->fork[philo->prev_index]->mutex);
		vars->fork[philo->prev_index]->nb++;
		vars->fork[philo->next_index]->nb++;
		pthread_mutex_unlock(&vars->fork[philo->next_index]->mutex);
		pthread_mutex_unlock(&vars->fork[philo->prev_index]->mutex);
		philo->nb_forks -= 2;
		philo->actual = 's';
		if (philo->nb_eat >= 0)
			philo->nb_eat++;
		if (philo->nb_eat == vars->nb_eat)
			vars->nb_finish++;
		philo->time_end_sleep = ft_gct() + vars->time_to_sleep;
	}
}
