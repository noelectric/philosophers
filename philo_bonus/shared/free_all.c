/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimzaoua <yimzaoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:32:01 by yimzaoua          #+#    #+#             */
/*   Updated: 2022/07/04 18:30:01 by yimzaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	free_all(t_philos **philo)
{
	t_philos	*tmp;
	t_philos	*lst;
	int			i;

	lst = *philo;
	i = 1;
	while (i <= lst->args->number_of_philosopher)
	{
		tmp = lst->next;
		free(lst);
		lst = NULL;
		if (tmp)
			lst = tmp;
		i++;
	}
}

void	check_p(t_philos *philos, t_args *args)
{
	int	i;
	int	status;

	i = 0;
	while (i < args->number_of_philosopher)
	{
		waitpid(-1, &status, 0);
		if (status == 0)
		{
			i = 0;
			printf("%ld %d died\n", time_stamp() - \
			philos->args->start, philos->philo_id);
			while (i < args->number_of_philosopher)
			{
				kill(philos->process_id, SIGKILL);
				i++;
				philos = philos->next;
			}
			exit (0);
		}
		i++;
	}
}
