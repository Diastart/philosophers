/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dias <dias@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:31:50 by dias              #+#    #+#             */
/*   Updated: 2025/04/21 15:12:26 by dias             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				meals_eaten;
	int				is_eating;
	long long		last_meal_time;
	struct s_data	*data;
	pthread_t		thread;
}				t_philo;

typedef struct s_data
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	int				someone_died;
	int				all_ate_enough;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	death_mutex;
	t_philo			*philos;
}				t_data;

typedef struct s_time
{
	long long	seconds;
	long long	microseconds;
}				t_time;

int			ft_atoi(const char *str);
int			parse_arguments(int ac, char *av[], t_data *data);
int			invalid_arguments_check(t_data *data);
int			init(t_data *data);
int			init_data(t_data *data);
void		init_philosophers(t_data *data);
long long	get_current_time(void);
void		ft_sleep(int milliseconds);
void		print_status(t_philo *philo, char *message);
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);
int			start_simulation(t_data *data);
int			is_simulation_finished(t_data *data);
void		*philo_routine(void *arg);
void		*monitor_routine(void *arg);
int			check_philosopher_death(t_data *data, int i);
int			check_all_ate_enough(t_data *data);
void		cleanup(t_data *data);
int			ft_strcmp(const char *s1, const char *s2);
void		join_threads(t_data *data);

#endif