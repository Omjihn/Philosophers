/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:53:34 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/21 15:30:14 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	ft_gct(void)
{
	struct timeval	tv;
	struct timezone	tz;
	long int		res;

	gettimeofday(&tv, &tz);
	res = tv.tv_sec * 1000;
	res += tv.tv_usec / 1000;
	return (res);
}

long int	ft_get(t_vars *vars)
{
	return (ft_gct() - vars->base_time);
}

int	main(int ac, char **av)
{
	t_vars	*vars;

	if (ac == 5 || ac == 6)
		vars = ft_init(ac, av);
	else
		vars = NULL;
	if (!vars)
	{
		printf(ERR ERR_1 ERR_2 ERR_3 ERR_4);
		return (0);
	}
	ft_init_threads(vars);
	while (vars->is_end == 0 && vars->nb_finish != vars->nb_forks)
	{
		usleep(300);
	}
	vars->is_end = 1;
	if (vars->nb_finish == vars->nb_forks)
		printf(GREEN EAT_MSG, ft_get(vars));
	usleep (50);
	ft_quit_all_threads(vars);
	usleep(50);
	ft_free_all(vars);
	return (0);
}
