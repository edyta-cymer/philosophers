/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:41:25 by ecymer            #+#    #+#             */
/*   Updated: 2024/12/30 00:17:18 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int     main(int argc, char *argv[])
{
    t_program           program;
    t_philo             philo[MAX_PHILOSOPHERS];
    pthread_mutex_t     forks[MAX_PHILOSOPHERS];
    
    if(5 == argc || 6 == argc)
    {
        validate_input(argv);
        printf("%s\n", "jupi");
        // 1. errors checking, filling table table
        //parse_input(&table, argv); 
        // 2. creating the actual thing
        init_data(&program, philo);
        init_philos(philo, &program, forks, argv);
        // 3. 
        //dinner_start(&table);
        // 4. No leaks ->phillo is full or one phillo died
        //clean(&table);
    }
    else
    {
        error_exit("wrong input");
    }
    return(0);
}

// next -> inicjalizacja forkow 