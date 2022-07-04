/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimzaoua <yimzaoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 02:29:55 by yimzaoua          #+#    #+#             */
/*   Updated: 2022/07/04 18:30:01 by yimzaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	event_p(int i, t_philos	*philo)
{
	if (!philo->args->dead)
	{
		if (i == 1)
		{
			printf("%ld %d has taken a fork\n", time_stamp() - \
			philo->args->start, philo->philo_id);
		}
		else if (i == 2)
		{
			printf("%ld %d is eating\n", time_stamp() - \
			philo->args->start, philo->philo_id);
		}
		else if (i == 3)
		{
			printf("%ld %d is sleepping\n", time_stamp() - \
			philo->args->start, philo->philo_id);
		}
		else if (i == 4)
		{
			printf("%ld %d  is thinking\n", time_stamp() - \
			philo->args->start, philo->philo_id);
		}
	}
}

void	eat_event(t_philos *philo, sem_t *mutex)
{
	long	start;

	sem_wait(mutex);
	event_p(1, philo);
	sem_wait(mutex);
	event_p(1, philo);
	event_p(2, philo);
	philo->eat_nb++;
	start = time_stamp();
	philo->last_eat = time_stamp();
	while (time_stamp() - start < philo->args->time_to_eat)
		usleep(100);
	sem_post(mutex);
	sem_post(mutex);
}

void	sleep_event(t_philos *philo)
{
	long	start;

	event_p(3, philo);
	start = time_stamp();
	while (time_stamp() - start < philo->args->time_to_sleep)
		usleep(100);
}

void	thinking_event(t_philos *philo)
{
	event_p(4, philo);
}
