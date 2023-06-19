/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life_cycle_extend.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:30:39 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/19 12:51:42 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_life_cycle_extend(t_philo *philo, t_vars *vars)
{
	vars->msg_dead = 1;
	ft_putstr_fd(RED, 1);
	ft_putnbr_fd(vars->current_time - vars->base_time, 1);
	ft_putstr_fd(" ms ", 1);
	ft_putnbr_fd(philo->pos, 1);
	ft_putstr_fd(" died\n", 1);
}
