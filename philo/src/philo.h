/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:51:42 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/14 15:02:30 by gbricot          ###   ########.fr       */
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

# define ARG_ERROR "Error please you need to enter 4 or 5 arguments :\n./philo [number_of_philosophers]\n\t[time_to_die]\n\t[time_to_eat]\n\t[time_to_sleep]\noptional :\n\t[number_of_times_each_philosopher_must_eat]\n"

# define MSG_SLEEP "%ld ms %d is sleeping\n"

# define MSG_THINK "%ld ms %d is thinking\n"

# define MSG_EAT "%ld ms %d is eating\n"

# define MSG_FORK "%ld ms %d has taken a fork\n"

typedef struct s_philo
{
	int			pos;
	int			index;
	int			next_index;
	int			prev_index;
	int			nb_forks;
	int			nb_eat;
	long int	time_to_die;
	long int	time_end_eat;
	long int	time_end_sleep;
	char		actual;
	pthread_t	thread;
}			t_philo;

typedef struct s_vars
{
	int				philo_nb;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	int				is_end;
	t_philo		*philos;
	long int		base_time;
	long int		current_time;
	pthread_t		trd[1];
	struct timeval	tv;
	struct timezone	tz;
	pthread_mutex_t	mutex;
}			t_vars;

int		ft_atoi(const char *nptr);

void	ft_init_threads(t_vars *vars);
void	ft_quit_all_threads(t_vars *vars);
void	ft_free_all(t_vars *vars);

void	*ft_philosopher(void *arg);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_count_time(void *arg);

t_vars	*ft_init(int ac, char **av);

#endif
