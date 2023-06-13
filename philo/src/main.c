/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:53:34 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/13 17:27:33 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_count_time(void *arg)
{
	t_vars	*vars;

	vars = (t_vars *) arg;
	while (vars->is_end == 0)
	{
		gettimeofday(&vars->tv, &vars->tz);
		vars->current_time = vars->tv.tv_sec * 1000;
		vars->current_time += vars->tv.tv_usec / 1000;
		usleep(500);
	}
	return (NULL);
}

static void	ft_init_threads(t_vars *vars)
{
	int	i;

	i = 1;
	pthread_create(&vars->trd[1], NULL, &ft_philosopher, vars);
	while (i <= vars->nb_forks)
	{
		pthread_join(vars->trd[i], NULL);
		i++;
	}
	pthread_mutex_init(&vars->mutex, NULL);
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
	pthread_create(&vars->trd[0], NULL, &ft_count_time, vars);
	ft_init_threads(vars);
	while (vars->is_end == 0)
	{
	}
	usleep (100);
	pthread_mutex_destroy(&vars->mutex);
	free(vars->trd);
	free(vars);
	return (0);
}
