/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:51:42 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/15 15:02:42 by gbricot          ###   ########.fr       */
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

# define ARG_ERR "Error please you need to enter 4 or 5 arguments :\n./philo "
# define ARG_ERR_1 "[number_of_philosophers] (int more than 1)\n\t[time_to_d"
# define ARG_ERR_2 "ie] (in ms)\n\t[time_to_eat] (in ms)\n\t[time_to_sleep] "
# define ARG_ERR_3 "(in ms)\noptional :\n\t[number_of_times_each_philosopher"
# define ARG_ERR_4 "_must_eat] (positive int)\n"

# define MSG_SLEEP "%ld ms %d is sleeping\n"

# define MSG_THINK "%ld ms %d is thinking\n"

# define MSG_EAT "%ld ms %d is eating\n"

# define MSG_FORK "%ld ms %d has taken a fork\n"

# define DEAD_MSG "%ld ms %d died\n"

# define EAT_MSG "%ld ms all philosophers have eaten\n"

typedef struct s_philo
{
	int			pos;
	int			index;
	int			next_index;
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
	int				nb_forks;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				starting_block;
	int				nb_eat;
	int				nb_finish;
	int				is_end;
	t_philo			**philos;
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
void	ft_life_cycle_extend(t_philo *philo, t_vars *vars);

void	*ft_philosopher(void *arg);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_count_time(void *arg);

t_vars	*ft_init(int ac, char **av);

#endif
