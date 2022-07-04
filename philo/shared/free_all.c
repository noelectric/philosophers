/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimzaoua <yimzaoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:32:01 by yimzaoua          #+#    #+#             */
/*   Updated: 2022/07/04 18:06:55 by yimzaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	free_all(t_philos **philo, t_args *args)
{
	t_philos	*tmp;
	t_philos	*lst;
	int			i;

	lst = *philo;
	i = 1;
	while (i <= lst->args->number_of_philosopher)
	{
		tmp = lst->next;
		pthread_mutex_destroy(&lst->fork);
		free(lst);
		lst = NULL;
		if (tmp)
			lst = tmp;
		i++;
	}
	pthread_mutex_destroy(&args->mutex);
}
