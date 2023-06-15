/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:17:12 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/15 17:57:01 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_all(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->philos[i])
	{
		free(vars->philos[i]);
		i++;
	}
	free (vars->philos);
	free (vars);
}

void	ft_quit_all_threads(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->philo_nb)
	{
		pthread_detach(vars->philos[i]->thread);
		i++;
	}
	while (pthread_join(vars->trd[0], NULL) == 0)
	{
	}
}
