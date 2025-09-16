/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:31:16 by manufern          #+#    #+#             */
/*   Updated: 2024/06/25 19:28:36 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

char	*drop_cero(char *num)
{
	int		i;
	 int negative;

	i = 1;
	negative = 0;
	if (num[0] == '-')
	{
		negative = 1;
	}
	while (num[i] == '0')
	{
		i ++;
	}
	if (num[i] == '\0')
		return ("0");
	if (negative)
	{
		num[i - 1] = '-';
        return num + (i - 1);
	}
    else
        return num + i;
}

int	is_number(char *number)
{
	int	i;

	i = 0;
	if (number[i] == '-')
		i++;
	while (number[i] != '\0')
	{
		if (number[i] < '0' || number[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	check_is_number(int i, int argc, char **argv)
{
	int	number_is;

	i = 0;
	while (i < argc)
	{
		number_is = is_number(argv[i]);
		if (argv[i][0] == '-' && argv[i][1] == '\0')
		{
			write_error();
			exit(-1);
		}
		if (argv[i][0] == '\0')
		{
			write_error();
			exit(-1);
		}
		if (number_is == 1)
		{
			write_error();
			exit(-1);
		}
		i++;
	}
}

void	comprobate_argument(int argc, char **argv)
{
	int	i;
	int	j;

	check_is_number(1, argc, argv);
	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (are_arguments_equal(argv[i], argv[j]))
			{
				write_error();
				exit (-1);
			}
			j++;
		}
		i++;
	}
}

void	ft_check_one_argument(char **argv)
{
	char	**one_argument;
	int		count_argc;

	if (argv[0][0] == '\0')
	{
		write_error();
		exit(-1);
	}
	one_argument = ft_split(*argv, ' ');
	count_argc = ft_counter(one_argument);
	comprobate_argument(count_argc, one_argument);
	ft_free(one_argument);
}
