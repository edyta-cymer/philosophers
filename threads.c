/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 02:55:14 by ecymer            #+#    #+#             */
/*   Updated: 2024/12/30 03:15:39 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_program *program, pthread_mutex_t *forks)
{
    pthread_t	observer;
	int			i;
    //pthread_create(&observer, NULL,
    //funkcja, program->philos);
    return(0);
}

// int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
//                    void *(*start_routine)(void *), void *arg);


// napisać funkcje check if all dead i check if all ate
// Sprawdza każdego filozofa, czy umarł:
//Blokowanie mutexu
// pthread_mutex_lock(philo->meal_lock);

// Porównuje bieżący czas (get_current_time) z czasem ostatniego posiłku (philo->last_meal).
// Sprawdza, czy minęło więcej czasu, niż pozwala na to time_to_die.
// Sprawdza również, czy filozof obecnie nie je (philo->eating == 0).
// Jeśli znajdzie martwego filozofa:
// Wypisuje komunikat.
// Ustawia flagę dead.
// Zwraca 1.
// Jeśli nikt nie umarł, zwraca 0.
// Zwalnianie mutexu, jeśli filozof żyje
// pthread_mutex_unlock(philo->meal_lock);
// return (0);
