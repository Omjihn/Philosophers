/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:09:37 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/16 16:12:01 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# define ERR "Error please you need to enter 4 or 5 arguments :\n./philo "
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

typedef struct s_vars
{

}		t_vars;

#endif
