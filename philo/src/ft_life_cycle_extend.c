/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life_cycle_extend.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:30:39 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/16 16:01:30 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_life_cycle_extend(t_philo *philo, t_vars *vars)
{
	vars->msg_dead = 1;
	ft_putnbr_fd(vars->current_time - vars->base_time, 1);
	write (1, " ms ", 4);
	ft_putnbr_fd(philo->pos, 1);
}
