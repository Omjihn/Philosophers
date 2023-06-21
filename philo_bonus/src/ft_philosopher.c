/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:21:42 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/21 18:16:01 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_philosopher(void *arg)
{
	t_vars	*vars;
	int	i;

	vars = (t_vars *) arg;
	i = 0;
	while (i < vars->nb_forks && (vars->pid[i] = fork()) > 0)
		i++;
	if ()
	while (vars->is_end == 0 && vars->nb_finish != vars->nb_forks)
        {
                usleep(300);
        }
	return (NULL);
}
