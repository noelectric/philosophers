/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimzaoua <yimzaoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:08:10 by yimzaoua          #+#    #+#             */
/*   Updated: 2022/07/04 18:29:16 by yimzaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>

typedef struct s_args{
	int				number_of_philosopher;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				dead;
	int				finish_eat;
	long			start;
	int				number_of_times_to_eat;
	int				id_dead_philo;
}	t_args;

typedef struct s_philos{
	int				philo_id;
	int				eat_nb;
	long long		last_eat;
	int				process_id;
	pthread_t		t_id;
	int				done_eating;
	t_args			*args;
	struct s_philos	*next;
}	t_philos;

long long	ft_atoi(const char *str);
t_philos	*lst_new(int data, t_args *args);
t_philos	*lstlast(t_philos *lst);
int			ft_lstsize(t_philos *lst);
void		ft_lstadd_back(t_philos **lst, t_philos *new);
long		time_stamp(void);
void		event_p(int i, t_philos	*philo);
void		eat_event(t_philos *philo, sem_t *mutex);
void		sleep_event(t_philos *philo);
void		thinking_event(t_philos *philo);
int			ft_isdigit(int arg);
int			check_input(char *av[]);
int			get_args(t_args *args, char *av[]);
void		routine(t_philos *philo, sem_t *mutex);
void		check_dead(t_philos *philos);
int			philo_init(t_philos **philo, t_args *args);
void		free_all(t_philos **philo);
void		check_p(t_philos *philos, t_args *args);
#endif
