/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:41:25 by ecymer            #+#    #+#             */
/*   Updated: 2024/12/18 18:04:37 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int     main(int argc, char *argv[])
{
    t_data *table;
    if(5 == argc || 6 == argc)
    {
        validate_input(argc, argv);
        // 1. errors checking, filling table table
        //parse_input(&table, argv); 
        // 2. creating the actual thing
        init_data(&table, argc, argv);
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