/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:08:18 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/16 16:31:16 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_count_time(void *arg)
{
	t_vars	*vars;

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
	return (0);
}
