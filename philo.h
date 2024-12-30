/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:59:31 by ecymer            #+#    #+#             */
/*   Updated: 2024/12/30 01:05:23 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // malloc, free
#include <stdio.h> // printf
#include <unistd.h> // write, usleep
#include <stdbool.h>
#include <pthread.h>
#include <sys/time.h> // gettimeofday
#include <limits.h> // INT_MAX
#include <errno.h>

#define MAX_PHILOSOPHERS 200

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_program
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}					t_program;

bool	validate_input(char *argv[]);
bool	validate_optional_input(const char *arg);
bool	is_valid_num(const char *arg);
void	init_data(t_program *program, t_philo *philo);
void	init_philo(t_philo *philo, int id, char *argv[], t_program *program);
void	init_philos(t_philo *philo, t_program *program,
			pthread_mutex_t *forks, char *argv[]);
size_t	get_current_time(void);
void	error_exit(const char *error);
int		ft_atoi(const char *str);
int		ft_isnum(char c);
