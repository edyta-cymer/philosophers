/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:41:33 by ecymer            #+#    #+#             */
/*   Updated: 2024/12/18 19:49:24 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		init_data(t_data **project, int argc, char *argv[])
{

	(void)argc;
	*project = (t_data *)malloc(sizeof(t_data));
	if(!project)
		return(1);
	(*project)->num_philosophers = ft_atoi(argv[1]);
	(*project)->time_to_die = ft_atoi(argv[2]);
	(*project)->time_to_eat = ft_atoi(argv[3]);
	(*project)->time_to_sleep = ft_atoi(argv[4]);
	//data->num_meals;
	//data->start_time
	//pthread_mutex_t *forks;
    //pthread_mutex_t print_lock;
    //t_philosopher *philosophers;
	return(0);
}