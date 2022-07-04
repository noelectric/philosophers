/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimzaoua <yimzaoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:08:10 by yimzaoua          #+#    #+#             */
/*   Updated: 2022/07/04 18:21:15 by yimzaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_args{
	int				number_of_philosopher;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				dead;
	int				finish_eat;
	long			start;
	pthread_mutex_t	mutex;
	int				number_of_times_to_eat;
}	t_args;

typedef struct s_philos{
	int				philo_id;
	int				eat_nb;
	long long		last_eat;
	pthread_t		t_id;
	pthread_mutex_t	fork;
	t_args			*args;
	struct s_philos	*next;
}	t_philos;

long long	ft_atoi(const char *str);
t_philos	*lst_new(int data, t_args *args);
t_philos	*lstlast(t_philos *lst);
int			ft_lstsize(t_philos *lst);
void		ft_lstadd_back(t_philos **lst, t_philos *new);
long		time_stamp(void);
int			mutex_lock(t_philos *philo);
void		event_p(int i, t_philos	*philo);
void		eat_event(t_philos *philo);
void		sleep_event(t_philos *philo);
void		thinking_event(t_philos *philo);
long		time_stamp(void);
int			ft_isdigit(int arg);
int			check_input(char *av[]);
int			get_args(t_args *args, char *av[]);
void		*routine(void *ptr);
void		free_all(t_philos **philo, t_args *args);

#endif
