/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:02:05 by manufern          #+#    #+#             */
/*   Updated: 2024/06/25 16:18:01 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i ++;
	}
	while (s2[j] != '\0')
	{
		str[i ++] = s2[j ++];
	}
	str[i] = '\0';
	return (str);
}

void	print_error(void)
{
	write(1, "Error\n", 6);
	exit (-1);
}

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
		print_error();
	return (num * sig);
}
