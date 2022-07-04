/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimzaoua <yimzaoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 02:42:37 by yimzaoua          #+#    #+#             */
/*   Updated: 2022/07/04 18:30:01 by yimzaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

long long	ft_atoi(const char *str)
{
	int		i;
	long	sign;
	long	r;

	i = 0;
	r = 0;
	sign = 1;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	while (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
		if (str[i] == 45 || str[i] == 43)
			return (0);
	}
	while (str[i] <= 57 && str[i] >= 48)
	{
		r = r * 10 + (str[i] - 48);
		i++;
	}
	return (sign * r);
}
