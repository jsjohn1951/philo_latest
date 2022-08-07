/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:35:07 by wismith           #+#    #+#             */
/*   Updated: 2022/08/07 23:57:01 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	print_(t_philo *philo, char *s)
{
	t_data	*data;

	data = (t_data *) philo->data;
	pthread_mutex_lock(&data->print);
	if (!ft_strncmp(s, "died", ft_strlen("died") - 1))
		printf("\x1B[31m");
	printf("%lums %d %s\n", new_stamp(data), philo->id, s);
	pthread_mutex_unlock(&data->print);
	if (!ft_strncmp(s, "is sleeping", ft_strlen("is sleeping") - 1))
		return (philo->local.ts_);
	if (!ft_strncmp(s, "is eating", ft_strlen("is eating") - 1))
		return (philo->local.te_);
	return (0);
}
