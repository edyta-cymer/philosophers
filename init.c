/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:41:33 by ecymer            #+#    #+#             */
/*   Updated: 2024/12/18 18:17:07 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}



int	ft_atoi(const char *str)
{
	int	num;
	int	sign;
	int	i;

	num = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]) && str[i] != '\0')
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isnum(str[i]) && str[i] != '\0')
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (num * sign);
}


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

// 0 - nazwa programu
// 1 - num_philo
// 2 - time_to_die
// 3 - time_to_eat
// 4 - time_to_sleep
// if jest to 5 - num of times each philo must eat