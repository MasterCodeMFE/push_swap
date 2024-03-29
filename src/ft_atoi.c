/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:02:05 by manufern          #+#    #+#             */
/*   Updated: 2024/02/13 15:52:18 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

int	ft_atoi(const char *str)
{
	long	i;
	long	num;
	long	sig;

	i = 0;
	num = 0;
	sig = 1;
	if (str == NULL)
		return (0);
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i ++;
	if (str[i] == '-')
		sig = -1;
	if (str[i] == '-' || str[i] == '+')
		i ++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i ++;
	}
	if (num * sig > 2147483647 || num * sig < -2147483648)
	{
		write(1, "Error\n", 6);
		exit (-1);
	}
	return (num * sig);
}