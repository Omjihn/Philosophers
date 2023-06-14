/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:24:43 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/14 16:31:35 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_threads(t_vars *vars)
{
        int	i;

	i = 0;
	while (i < vars->nb_forks)
	{
		pthread_create(&vars->philos[i].thread, NULL, &ft_philosopher, vars);
		i++;
	}
	pthread_mutex_init(&vars->mutex, NULL);
}

static char	ft_check_numbers(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i] && i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
			{
				printf("Error please enter only numbers\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

t_vars	*ft_init(int ac, char **av)
{
	t_vars	*vars;

	if (ft_check_numbers(ac, av) == 0)
		return (NULL);
	vars = (t_vars *) ft_calloc (sizeof(t_vars), 1);
	if (!vars)
		return (NULL);
	vars->nb_forks = ft_atoi(av[1]);
	vars->time_to_die = ft_atoi(av[2]);
	vars->time_to_eat = ft_atoi(av[3]);
	vars->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		vars->nb_eat = ft_atoi(av[5]);
	else
		vars->nb_eat = -1;
	vars->philos = (t_philo *) ft_calloc (sizeof(t_philo), vars->nb_forks + 1);
	if (!vars->philos)
	{
		return (NULL);
		ft_free_all(vars);
	}
	gettimeofday(&vars->tv, &vars->tz);
	vars->base_time = vars->tv.tv_sec * 1000;
	vars->base_time += vars->tv.tv_usec / 1000;
	return (vars);
}
