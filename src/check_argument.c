/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:31:16 by manufern          #+#    #+#             */
/*   Updated: 2024/02/08 15:50:12 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

char *drop_cero(char *num)
{
	int i;

	i = 1;
	while(num[i] == '0')
	{
		i ++;
	}
	if (num[i] == '\0')
		return ("0");
	return (num);
}

int is_number(char *number)
{
	int i;

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

void check_is_number (int i, int argc, char ** argv)
{
	int number_is;
	
	i = 1;
	while (i < argc)
	{
		number_is = is_number(argv[i]);
		if (argv[i][0] == '\0')
		{
			printf("Algun argumento no es un numero\n");
			exit(-1);
		} 
		if (number_is == 1)
		{
			printf("Algun argumento no es un numero\n");
			exit(-1);
		}
		i++;
	}
}

void comprobate_argument(int argc, char **argv)
{
	int i;
	int j;
	
	check_is_number(1, argc, argv);
	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (are_arguments_equal(argv[i], argv[j]))
			{
				printf("Los argumentos %d y %d son iguales: %s\n", i, j, argv[i]);
				exit (-1);
			}
			j++;
		}

		i++;
	}
	printf("Todos los argumentos son numeros\n");
}

void ft_check_one_argument(char **argv)
{
	char **one_argument;
	int count_argc;
	
	if (argv[1][0] == '\0')
	{
		printf("Algun argumento no es un numero\n");
		exit(-1);
	} 
	printf("Solo un argumento\n");
	one_argument = ft_split(argv[1], ' ');
	count_argc = ft_counter(one_argument);
	if (count_argc == 1)
	{
		printf("ya ordenado\n");
		exit (1);
	}
	comprobate_argument(count_argc, one_argument);
}
