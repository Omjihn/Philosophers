/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:53:34 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/16 15:42:09 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_count_time(void *arg)
{
	t_vars			*vars;

	vars = (t_vars *) arg;
	pthread_mutex_lock(&vars->mutex);
	gettimeofday(&vars->tv, &vars->tz);
	vars->base_time = vars->tv.tv_sec * 1000;
	vars->base_time += vars->tv.tv_usec / 1000;
	pthread_mutex_unlock(&vars->mutex);
	while (vars->is_end == 0 && (vars->nb_forks != vars->nb_finish))
	{
		pthread_mutex_lock(&vars->mutex);
		gettimeofday(&vars->tv, &vars->tz);
		vars->current_time = vars->tv.tv_sec * 1000;
		vars->current_time += vars->tv.tv_usec / 1000;
		if (vars->starting_block == 0)
			vars->starting_block++;
		pthread_mutex_unlock(&vars->mutex);
		usleep(1000);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_vars	*vars;

	if (ac == 5 || ac == 6)
		vars = ft_init(ac, av);
	else
		printf(ERR ERR_1 ERR_2 ERR_3 ERR_4);
	if (!vars)
		return (0);
	ft_init_threads(vars);
	pthread_create(&vars->trd[0], NULL, &ft_count_time, vars);
	while (vars->is_end == 0 && (vars->nb_forks != vars->nb_finish))
	{
	}
	if (vars->nb_forks == vars->nb_finish)
		printf (GREEN EAT_MSG, vars->current_time - vars->base_time);
	usleep(10000);
	ft_quit_all_threads(vars);
	pthread_mutex_destroy(&vars->mutex);
	ft_free_all(vars);
	usleep (10000);
	return (0);
}
