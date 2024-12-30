/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:41:25 by ecymer            #+#    #+#             */
/*   Updated: 2024/12/30 02:56:40 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_program			program;
	t_philo				philo[MAX_PHILOSOPHERS];
	pthread_mutex_t		forks[MAX_PHILOSOPHERS];

	if (5 == argc || 6 == argc)
    {
        validate_input(argv);
        init_data(&program, philo);
        init_forks(forks, ft_atoi(argv[1]));
        init_philos(philo, &program, forks, argv);
        create_thread(&program, forks);
        // 3. 
        //dinner_start(&table);
        // 4. No leaks ->phillo is full or one phillo died
        //clean(&table);
    }
    else
    	error_exit("wrong input");
    return(0);
}

// next -> CREATE_THREADS 