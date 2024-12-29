/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:41:33 by ecymer            #+#    #+#             */
/*   Updated: 2024/12/30 00:19:24 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	init_philo(t_philo *philo, int id, char *argv[], t_program *program)
{
		philo->id = id;
		philo->eating = 0;
		philo->meals_eaten = 0;
		philo->num_of_philos = ft_atoi(argv[1]);
		philo->time_to_die = ft_atoi(argv[2]);
		philo->time_to_eat = ft_atoi(argv[3]);
		philo->time_to_sleep = ft_atoi(argv[4]);
		philo->start_time = get_current_time();
		philo->last_meal = get_current_time();
		if(argv[5])
			philo->num_times_to_eat = ft_atoi(argv[5]);
		else
			philo->num_times_to_eat = -1;
		philo->write_lock = &program->write_lock;
		philo->dead_lock = &program->dead_lock;
		philo->meal_lock = &program->meal_lock;
		philo->dead = &program->dead_flag;
}

void	init_philos(t_philo *philo, t_program *program, pthread_mutex_t *forks, char *argv[])
{
	int		i;
	int		num_of_philos;

	i = 0;
	num_of_philos = ft_atoi(argv[1]);
	while(i < num_of_philos)
	{
		init_philo(&philo[i], i + 1, argv, program);
		philo[i].l_fork = &forks[i];
		if (i == 0)
			philo[i].r_fork = &forks[philo[i].num_of_philos - 1];
		else
			philo[i].r_fork = &forks[i - 1];
		i++;
	}
}

void		init_data(t_program *program, t_philo *philo)
{
	program->dead_flag = 0;
	program->philos = philo;
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
}