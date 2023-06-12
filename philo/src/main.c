/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:53:34 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/12 18:45:17 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_count_time(void *arg)
{
	t_vars	*vars;

	vars = (t_vars *) arg;
	while (1)
	{
		gettimeofday(&vars->tv, &vars->tz);
		vars->current_time = vars->tv.tv_sec * 1000;
		vars->current_time += vars->tv.tv_usec / 1000;
		usleep(1000);
	}
}

void	ft_render_time(t_vars *vars)
{
	printf("Run time : %ld ms\n", vars->current_time - vars->base_time);
}

int	main(int ac, char **av)
{
	t_vars	*vars;

	if  (ac == 5 || ac == 6)
		vars = ft_init(ac, av);
	if (!vars)
	{
		printf(ARG_ERROR);
		return (0);
	}
	vars->trd = (pthread_t *) ft_calloc(sizeof(pthread_t), 2);
	gettimeofday(&vars->tv, &vars->tz);
	vars->base_time = vars->tv.tv_sec * 1000;
	vars->base_time += vars->tv.tv_usec / 1000;
	pthread_create(&vars->trd[0], NULL, ft_count_time, vars);
	while (1)
	{
		ft_render_time(vars);
		usleep(1000);
	}
}
