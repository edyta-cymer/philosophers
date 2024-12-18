/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:41:16 by ecymer            #+#    #+#             */
/*   Updated: 2024/12/18 18:17:14 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

bool    validate_input(int argc, char *argv[])
{
    int     i;
    int     j;

    i = 1;
    while(i < argc)
    {
        j = 0;
        while(argv[i][j])
        {
            if(ft_isnum(argv[i][j]) == 0)
            {
                printf("Error: Argument %d contains invalid characters.\n", i);
                return(false);
            }
            j++;
        }
        if (atoi(argv[i]) <= 0)
        {
            printf("Error: Argument %d must be a positive number.\n", i);
            return false;
        }
        i++;
    }
    return(true);
}

//while argv[1][i]
