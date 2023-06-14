/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life_cycle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:44:05 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/14 18:21:02 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo	ft_init_philo(t_vars *vars)
{
	t_philo	philo;

        philo.index = vars->philo_nb;
	if (philo.index == 0)
		philo.prev_index = vars->philo_nb - 1;
	else
		philo.prev_index = philo.index - 1;
	if (philo.index == philo_nb - 1)
		philo.next_index = 0;
	else
		philo.next_index = philo_index + 1;
        philo.pos = vars->philo_nb + 1;
        philo.nb_eat = vars->nb_eat;
        philo.actual = 's';
	philo.time_end_sleep = 0;
        philo.time_end_eat = 0;
	philo.nb_forks = 1;
        philo.time_to_die = vars->time_to_die + vars->current_time;
	vars->philo_nb++;
	return (philo);
}

static void	ft_philo_eat(t_philo philo)
{
	pthread_mutex_lock(&vars->mutex);
	printf(MSG_EAT, vars->current_time - vars->base_time , philo.pos);
	philo.time_end_eat = vars->current_time + vars->time_to_eat;
	while (vars->current_time < philo.time_end_eat && vars->is_end == 0)
        {
        }
        pthread_mutex_unlock(&vars->mutex);
        philo.time_to_die = vars->current_time + vars->time_to_die;
        philo.actual = 'e';
	retunr (philo);
}

static void	ft_steal_fork(t_philo philo, t_vars *vars)
{
	if (vars->philos[philo->next_index9999999999])

void	*ft_philosopher(void *arg)
{
	t_vars	*vars;
	t_philo	philo;

	vars = (t_vars *) arg;
	philo = ft_init_philo(vars);
	while (vars->nb_forks != vars->philo_nb)
	{
	}
	//if they are unsync maybe wait for a bool when all philos are launched
	while (philo.time_to_die > vars->current_time  && vars->is_end == 0)
	{
		if (philo.nb_forks == 2 && philo.actual == 't' && vars->is_end == 0)
			philo = ft_philo_eat(philo);
		else if (philo.actual == 't' &&  philo.nb_forks < 2 && vars->is_end == 0)
			philo = ft_steal_fork(philo);
		else if (philo.actual == 'e' && vars->is_end == 0)
		{
			printf(MSG_SLEEP, vars->current_time - vars->base_time , philo.pos);
			philo.time_end_sleep = vars->current_time + vars->time_to_sleep;
			philo.actual = 's';
		}
		else if (philo.actual == 's' && vars->current_time >= philo.time_end_sleep && vars->is_end == 0)
		{
			printf(MSG_THINK, vars->current_time - vars->base_time, philo.pos);
			philo.actual = 't';
		}
	}
	if (vars->is_end == 0)
	{
		vars->is_end = 1;
		printf("%ld ms philo %d is dead\n",vars->current_time - vars->base_time , philo.pos);
	}

	return (NULL);
}
