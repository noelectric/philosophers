/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimzaoua <yimzaoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:29:14 by yimzaoua          #+#    #+#             */
/*   Updated: 2022/07/04 18:30:01 by yimzaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

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

void	routine(t_philos *philo, sem_t *mutex)
{
	if (philo->philo_id % 2 == 0)
		usleep(100);
	while (!philo->args->dead)
	{
		eat_event(philo, mutex);
		sleep_event(philo);
		thinking_event(philo);
	}
	sem_close(mutex);
}
