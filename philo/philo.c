/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimzaoua <yimzaoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:07:51 by yimzaoua          #+#    #+#             */
/*   Updated: 2022/07/04 18:06:47 by yimzaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	thread_init(t_philos **philo, t_args *args)
{
	int			i;
	t_philos	*tmp;

	i = 1;
	tmp = *philo;
	while (i <= args->number_of_philosopher)
	{
		pthread_create(&tmp->t_id, NULL, &routine, tmp);
		tmp = tmp->next;
		i++;
	}
}

int	philo_init(t_philos **philo, t_args *args)
{
	t_philos	*tmp;
	int			i;

	i = 0;
	*philo = NULL;
	tmp = *philo;
	while (++i <= args->number_of_philosopher)
	{
		tmp = lst_new(i, args);
		ft_lstadd_back(philo, tmp);
	}
	tmp->next = *philo;
	return (0);
}

void	check_dead(t_philos *philos)
{
	while (1)
	{
		if (time_stamp() - philos->last_eat > philos->args->time_to_die)
		{
			philos->args->dead = 1;
			pthread_mutex_lock(&philos->args->mutex);
			printf("%lld %d  died\n", time_stamp() - \
			philos->last_eat, philos->philo_id);
			return ;
		}
		if (philos->args->number_of_philosopher == philos->args->finish_eat)
		{
			philos->args->dead = 1;
			return ;
		}
		philos = philos->next;
		usleep(500);
	}
}

int	main(int ac, char *av[])
{
	t_args		args;
	t_philos	*philos;
	int			check;

	if (ac != 5 && ac != 6)
		return (write(1, "ERROR\n", 6));
	if (!check_input(av))
		return (write(1, "ERROR\n", 6));
	check = get_args(&args, av);
	if (check == 0)
		return (write(1, "ERROR\n", 6));
	if (check == 3)
		return (0);
	philo_init(&philos, &args);
	thread_init(&philos, &args);
	check_dead(philos);
	free_all(&philos, &args);
	return (0);
}
