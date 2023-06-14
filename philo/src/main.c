/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:53:34 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/14 15:02:28 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_count_time(void *arg)
{
	t_vars	*vars;
	pthread_mutex_t	mutex;

	vars = (t_vars *) arg;
	pthread_mutex_init(&mutex, NULL);
	while (vars->is_end == 0)
	{
		pthread_mutex_lock(&mutex);
		gettimeofday(&vars->tv, &vars->tz);
		vars->current_time = vars->tv.tv_sec * 1000;
		vars->current_time += vars->tv.tv_usec / 1000;
		pthread_mutex_unlock(&mutex);
		usleep(500);
	}
	pthread_mutex_destroy(&mutex);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_vars	*vars;

	if (ac == 5 || ac == 6)
		vars = ft_init(ac, av);
	if (!vars)
	{
		printf(ARG_ERROR);
		return (0);
	}
	pthread_create(vars->trd, NULL, &ft_count_time, vars);
	ft_init_threads(vars);
	while (vars->is_end == 0)
	{
	}
	pthread_mutex_destroy(&vars->mutex);
	ft_quit_all_threads(vars);
	ft_free_all(vars);
	return (0);
}
