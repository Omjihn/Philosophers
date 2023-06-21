/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:51:42 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/19 12:46:10 by gbricot          ###   ########.fr       */
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

# define ERR "./philo "
# define ERR_1 "[number_of_philosophers] (max 32754)\n\t[time_to_d"
# define ERR_2 "ie] (ms)\n\t[time_to_eat] (ms)\n\t[time_to_sleep] "
# define ERR_3 "(ms)\noptional :\n\t[number_of_times_each_philosopher"
# define ERR_4 "_must_eat] (positive int)\n"

# define MSG_SLEEP "%ld ms %d is sleeping\n"

# define MSG_THINK "%ld ms %d is thinking\n"

# define MSG_EAT "%ld ms %d is eating\n"

# define MSG_FORK "%ld ms %d has taken a fork\n"

# define DEAD "%ld ms %d died\n"

# define EAT_MSG "%ld ms all philosophers have eaten\n"

# define OF_MSG "Error check if your arguments does not overflow\n"

# define TRD_MSG "Error number of philosopher must be betwin 0 and 32755\n"

# define GREEN "\033[0;32m"

# define RED "\033[0;31m"

# define WTE "\033[0;37m"

typedef struct s_philo
{
	int				pos;
	int				index;
	int				next_index;
	int				prev_index;
	int				nb_forks;
	int				nb_eat;
	char			actual;
	long int		time_to_die;
	long int		time_end_eat;
	long int		time_end_sleep;
	pthread_t		thread;
}			t_philo;

typedef struct s_fork
{
	char			nb;
	pthread_mutex_t	mutex;
}			t_fork;

typedef struct s_vars
{
	int				philo_nb;
	int				nb_forks;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	int				nb_finish;
	int				is_end;
	int				msg_dead;
	char			error;
	t_philo			**philos;
	t_fork			**fork;
	long int		base_time;
	long int		current_time;
	pthread_t		trd[1];
	pthread_mutex_t	mutex;
}			t_vars;

/*		UTILS			*/

int			ft_atoi(const char *nptr, t_vars *vars);

void		*ft_calloc(size_t nmemb, size_t size);

/*		GET_TIME		*/

long int	ft_get(t_vars *vars);
long int	ft_gct(void);

/*		INIT/CLEAR		*/

void		ft_init_threads(t_vars *vars);
void		ft_quit_all_threads(t_vars *vars);
void		ft_free_all(t_vars *vars);

t_vars		*ft_init(int ac, char **av);

/*		PHILOS_ROUTINE		*/

void		ft_is_dead(t_vars *vars, t_philo *philo);
void		ft_steal_fork(t_vars *vars, t_philo *philo);
void		ft_eat(t_vars *vars, t_philo *philo);
void		ft_think(t_vars *vars, t_philo *philo);
void		ft_sleep(t_vars *vars, t_philo *philo);

void		*ft_philosopher(void *arg);

#endif
