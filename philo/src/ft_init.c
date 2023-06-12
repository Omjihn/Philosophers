/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:24:43 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/12 18:38:33 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_numbers(int ac , char **av)
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
	vars->trd = ft_calloc(sizeof(pthread_t), vars->nb_forks + 2);
	return (vars);
}
