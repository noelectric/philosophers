/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimzaoua <yimzaoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:29:14 by yimzaoua          #+#    #+#             */
/*   Updated: 2022/07/04 18:13:43 by yimzaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	get_args(t_args *args, char *av[])
{
	int	i;

	i = -1;
	args->number_of_philosopher = ft_atoi(av[1]);
	if (!args->number_of_philosopher)
		return (0);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_sleep = ft_atoi(av[4]);
	args->time_to_eat = ft_atoi(av[3]);
	args->start = time_stamp();
	pthread_mutex_init(&args->mutex, NULL);
	args->dead = 0;
	if (av[5])
	{
		args->number_of_times_to_eat = ft_atoi(av[5]);
		if (!args->number_of_times_to_eat)
			return (3);
	}
	else
		args->number_of_times_to_eat = -1;
	return (1);
}

void	*routine(void *ptr)
{
	t_philos	*philo;

	philo = (t_philos *)ptr;
	if (philo->philo_id % 2 == 0)
		usleep(100);
	while (!philo->args->dead)
	{
		eat_event(philo);
		sleep_event(philo);
		thinking_event(philo);
	}
	return (NULL);
}
