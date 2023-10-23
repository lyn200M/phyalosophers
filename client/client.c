/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:42:16 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/23 22:30:43 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int thread_number;
    pthread_t thread;
} t_threads;

void* thread_function(void* arg) {
    t_threads* thread_info = (t_threads*)arg;
    printf("Thread %d created.\n", thread_info->thread_number);
    // D'autres opérations peuvent être effectuées ici
    return NULL;
}







int	main(int ac, char **av)
{
	if (!is_good_argument(ac, av))
		return (0);
	report_log_info(CHECK_ARGS_OK_LOG);
	int num_threads = atoi(av[1]);

    if (num_threads <= 0) {
        printf("Le nombre de threads doit être supérieur à zéro.\n");
        return 1;
    }
 	 t_threads*** thread_data = NULL;
    int num_groups = 2;

    if (num_threads % 2 != 0) {
        num_groups = 3;
    }

    thread_data = (t_threads***)malloc(num_groups * sizeof(t_threads**));

    for (int i = 0; i < num_groups; i++) {
        int current_group_size = (i < num_groups - 1) ? (num_threads / num_groups) : 1;
        thread_data[i] = (t_threads**)malloc(current_group_size * sizeof(t_threads));
    }

    // Création des threads
    int thread_number = 1;
    for (int i = 0; i < num_groups; i++) {
        int current_group_size = (i < num_groups - 1) ? (num_threads / num_groups) : 1;
        for (int j = 0; j < current_group_size; j++) {
            thread_data[i][j] = (t_threads*)malloc(sizeof(t_threads));
            thread_data[i][j]->thread_number = thread_number;
            pthread_create(&thread_data[i][j]->thread, NULL, thread_function, thread_data[i][j]);
            thread_number++;
        }
    }

    // Attendre la fin des threads et les détruire
    for (int i = 0; i < num_groups; i++) {
        int current_group_size = (i < num_groups - 1) ? (num_threads / num_groups) : 1;
        for (int j = 0; j < current_group_size; j++) {
            pthread_join(thread_data[i][j]->thread, NULL);
            free(thread_data[i][j]);
        }
        free(thread_data[i]);
    }

    // Libérer la mémoire
    free(thread_data);
	return(0);
}

bool	is_good_argument(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		report_log_error(NUMBER_ARGUMENTS_ERROR);
		return (false);
	}
	if (!is_all_number(av))
	{
		report_log_error(ARGUMENTS_NOT_NUMBER_ERROR);
		return (false);
	}
	return (true);
}

