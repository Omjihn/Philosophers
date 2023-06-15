/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:53:34 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/15 15:11:33 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_count_time(void *arg)
{
	t_vars			*vars;

	vars = (t_vars *) arg;
	gettimeofday(&vars->tv, &vars->tz);
	vars->base_time = vars->tv.tv_sec * 1000;
	vars->base_time += vars->tv.tv_usec / 1000;
	vars->starting_block = 1;
	while (vars->is_end == 0)
	{
		pthread_mutex_lock(&vars->mutex);
		gettimeofday(&vars->tv, &vars->tz);
		vars->current_time = vars->tv.tv_sec * 1000;
		vars->current_time += vars->tv.tv_usec / 1000;
		pthread_mutex_unlock(&vars->mutex);
		usleep(500);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_vars	*vars;

	if (ac == 5 || ac == 6)
		vars = ft_init(ac, av);
	if (!vars)
	{
		printf(ARG_ERR ARG_ERR_1 ARG_ERR_2 ARG_ERR_3 ARG_ERR_4);
		return (0);
	}
	ft_init_threads(vars);
	pthread_create(vars->trd, NULL, &ft_count_time, vars);
	while (vars->is_end == 0)
	{
	}
	ft_quit_all_threads(vars);
	pthread_mutex_destroy(&vars->mutex);
	ft_free_all(vars);
	return (0);
}
