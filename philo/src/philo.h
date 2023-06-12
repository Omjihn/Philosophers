/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:51:42 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/12 16:30:09 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

#define ARG_ERROR "Error please you need to enter 4 or 5 arguments :\n./philo [number_of_philosophers]\n\t[time_to_die]\n\t[time_to_eat]\n\t[time_to_sleep]\noptional :\n\t[number_of_times_each_philosopher_must_eat]\n"

typedef struct s_philo
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_think;
}			t_philo;

typedef struct s_vars
{

	int	nb_forks;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_eat;
	pthread_t *trd;
	struct timeval tv;
	struct timezone tz;
	long int	base_time;
	long int	current_time;
}			t_vars;

int	ft_atoi(const char *nptr);

void	*ft_calloc(size_t nmemb, size_t size);
void    *ft_count_time(void *arg);

t_vars	*ft_init(int ac, char **av);

#endif
