/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:19:57 by manufern          #+#    #+#             */
/*   Updated: 2024/01/29 19:28:23 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char *drop_cero(char *num)
{
	int i;
	while 
}

int are_arguments_equal(char *arg1, char *arg2)
{
	if (arg1[0] == '-' && arg1[1] == '0')
    {
       arg1 = drop_cero (arg1);
    }
	if (arg2[0] == '-' && arg2[1] == '0')
    {
        arg2 = drop_cero (arg2);
    }
	if (*arg1 == '-' && *arg2 == '-')
	{
		arg1 ++;
		arg2 ++;
	}
	if (*arg1 != '\0' && *arg1 == '0')
	{
		while(*arg1 == '0')
		{
			arg1 ++;
		}
		if (*arg1 == '\0')
		{
			arg1 = "0\0";
		}
	}
	if (*arg2 != '\0' && *arg2 == '0')
	{
		while(*arg2 == '0')
		{
			arg2++;
		}
		if (*arg2 == '\0')
		{
			arg2 = "0\0";
		}
	}
	while (*arg1 != '\0' && *arg2 != '\0')
	{
		if (*arg1 != *arg2)
		{
			return (0);
		}

		arg1 ++;
		arg2 ++;
	}
	if (*arg1 != '\0' || *arg2 != '\0')
	{
		return 0;
	}
	return (1);
}

int is_number(char *number)
{
	int i;

	i = 0;
	if (number[i] == '-')
		i++;

	while (number[i] != '\0') {
		if (number[i] < '0' || number[i] > '9')
			return (1);
		i++;
	}

	return (0);
}

void comprobate_argument(int argc, char **argv)
{
	int i;
	int j;
	int number_is;
	
	i = 1;
	while (i < argc) {
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

int main(int argc, char **argv)
{   
	if (argc <= 1)
	{
		printf ("no hay argumentos");
		return (-1);
	}
	printf ("hay argumentos\n");
	if (argc > 2)
		comprobate_argument(argc, argv);
	else
		printf("Solo un argumento");
	return (0);
}


/*Para errores en write(2, "", n)*/
/*Varibles glovales proividas*/
/*$>./push_swap 0 one 2 3
Error*/