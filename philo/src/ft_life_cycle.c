/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life_cycle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:44:05 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/13 15:26:01 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philosopher(void *arg)
{
	t_vars	*vars;
	t_philo	philo;

	vars = (t_vars *) arg;
	vars->philo_nb++;
	philo.philo_nb = vars->philo_nb;
	philo.time_to_die = vars->time_to_die + vars->current_time;
	philo.nb_eat = vars->nb_eat;
	philo.time_end_sleep = 0;
	philo.nb_forks = 0;
	philo.actual = 's';
	//if they are unsync maybe wait for a bool when all philos are launched
	while (philo.time_to_die > vars->current_time && vars->is_end == 0)
	{
		if (philo.nb_forks == 2 && philo.actual == 't' && vars->is_end == 0)
		{
			printf(MSG_EAT, vars->current_time - vars->base_time , philo.philo_nb);
			philo.time_end_eat = vars->current_time + vars->time_to_eat;
			while (vars->current_time < philo.time_end_eat)
			{
			}
			pthread_mutex_lock(&vars->mutex);
			vars->nb_forks += 2;
			pthread_mutex_unlock(&vars->mutex);
			philo.nb_forks = 0;
			philo.time_to_die = vars->current_time + vars->time_to_die;
			philo.actual = 'e';
		}
		else if (philo.actual == 't' && vars->is_end == 0)
		{
			if (vars->nb_forks > 0)
			{
				pthread_mutex_lock(&vars->mutex);
                        	vars->nb_forks--;
                        	pthread_mutex_unlock(&vars->mutex);
				printf(MSG_FORK, vars->current_time - vars->base_time, philo.philo_nb);
				philo.nb_forks++;
			}
		}
		else if (philo.actual == 'e' && vars->is_end == 0)
		{
			printf(MSG_SLEEP, vars->current_time - vars->base_time , philo.philo_nb);
			philo.time_end_sleep = vars->current_time + vars->time_to_sleep;
			philo.actual = 's';
		}
		else if (philo.actual == 's' && vars->current_time >= philo.time_end_sleep && vars->is_end == 0)
		{
			printf(MSG_THINK, vars->current_time - vars->base_time, philo.philo_nb);
			philo.actual = 't';
		}
	}
	if (vars->is_end == 0)
	{
		vars->is_end = 1;
		printf("%ld ms philo %d is dead\n",vars->current_time - vars->base_time , philo.philo_nb);
	}
	return (NULL);
}
