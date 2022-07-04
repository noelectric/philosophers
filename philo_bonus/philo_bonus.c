/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimzaoua <yimzaoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:07:51 by yimzaoua          #+#    #+#             */
/*   Updated: 2022/07/04 18:30:38 by yimzaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo_bonus.h"

void	c_thread(t_philos *philo, sem_t *mutex)
{
	philo->last_eat = time_stamp();
	pthread_create(&(philo->t_id), NULL, (void *)check_dead, \
	(void *)philo);
	while (!philo->args->dead)
		routine(philo, mutex);
	if (philo->done_eating == 1)
		exit(1);
	exit(0);
}

int	thread_init(t_philos **philo, t_args *args)
{
	int			i;
	t_philos	*tmp;
	int			id;
	sem_t		*mutex;

	i = 1;
	id = 1;
	tmp = *philo;
	sem_unlink("mutex");
	mutex = sem_open("mutex", O_CREAT, 666, args->number_of_philosopher);
	if (!tmp)
		return (1);
	while (i <= args->number_of_philosopher && tmp)
	{
		tmp->process_id = fork();
		if (tmp->process_id < 0)
			exit(0);
		else if (tmp->process_id == 0)
			c_thread(*philo, mutex);
		tmp = tmp->next;
		i++;
	}
	return (0);
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
	t_philos	*philo;

	philo = (t_philos *)philos;
	while (1)
	{
		if (time_stamp() - philos->last_eat > philos->args->time_to_die)
			exit (0);
		if (philo->args->number_of_times_to_eat == philos->eat_nb)
		{
			philo->args->dead = 1;
			philo->done_eating = 1;
			return ;
		}
		usleep(500);
	}
}

int	main(int ac, char *av[])
{
	t_args		args;
	t_philos	*philos;
	int			i;

	if (ac != 5 && ac != 6)
		return (write(1, "ERROR\n", 6));
	if (!check_input(av))
		return (write(1, "ERROR\n", 6));
	i = get_args(&args, av);
	if (i == 0)
		return (write(1, "ERROR\n", 6));
	if (i == 3)
		return (0);
	philo_init(&philos, &args);
	if (thread_init(&philos, &args))
		return (write(1, "ERROR\n", 6));
	check_p(philos, &args);
	free_all(&philos);
	return (0);
}
