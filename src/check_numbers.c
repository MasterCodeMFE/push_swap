/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 10:19:41 by manufern          #+#    #+#             */
/*   Updated: 2024/06/25 19:22:46 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	write_error(void)
{
	write (1, "Error\n", 6);
}

char	*handle_negative_zero(char *arg)
{
	if (arg[0] == '-' && arg[1] == '0')
	{
		return (drop_cero(arg));
	}
	return (arg);
}

char	*remove_leading_zeros(char *arg)
{
	while (*arg != '\0' && *arg == '0')
	{
		arg++;
	}
	if (*arg == '\0')
	{
		return ("0\0");
	}
	return (arg);
}

int	compare_arguments(char *arg1, char *arg2)
{
	while (*arg1 != '\0' && *arg2 != '\0')
	{
		if (*arg1 != *arg2)
		{
			return (0);
		}
		arg1++;
		arg2++;
	}
	if (*arg1 != '\0' || *arg2 != '\0')
	{
		return (0);
	}
	return (1);
}

int	are_arguments_equal(char *arg1, char *arg2)
{
	arg1 = handle_negative_zero(arg1);
	arg2 = handle_negative_zero(arg2);
	arg1 = remove_leading_zeros(arg1);
	arg2 = remove_leading_zeros(arg2);
	return (compare_arguments(arg1, arg2));
}
