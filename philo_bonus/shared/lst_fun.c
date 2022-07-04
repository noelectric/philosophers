/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimzaoua <yimzaoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:39:02 by yimzaoua          #+#    #+#             */
/*   Updated: 2022/07/04 18:30:01 by yimzaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	ft_lstsize(t_philos *lst)
{
	int	count;

	count = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		count ++;
		lst = lst->next;
	}
	return (count);
}

t_philos	*lstlast(t_philos *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_philos **lst, t_philos *new)
{
	t_philos	*root;

	root = *lst;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	else
	{
		while (root->next != NULL)
			root = root->next;
		root->next = new;
	}
}

t_philos	*lst_new(int data, t_args *args)
{
	t_philos	*new_element;

	new_element = (t_philos *)malloc(sizeof(t_philos));
	if (!new_element)
		return (0);
	new_element->philo_id = data;
	new_element->args = args;
	new_element->last_eat = time_stamp();
	new_element->eat_nb = 0;
	new_element->args->finish_eat = 0;
	new_element->done_eating = 0;
	new_element->next = NULL;
	return (new_element);
}
