/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:19:57 by manufern          #+#    #+#             */
/*   Updated: 2024/02/05 17:03:49 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

int ft_count_words(char **argument)
{
	int	i;

	    i = 0;
	while (argument[i])
	{
		i ++;
	}
	printf("palabras: %i\n", i);
	return (i);
}

int main(int argc, char **argv)
{
	char **argument;
	if (argc <= 1)
	{
		printf ("no hay argumentos");
		return (-1);
	}
	printf ("hay argumentos\n");
	if (argc > 2)
	{
		comprobate_argument(argc, argv);
		create_stack_a(argc, argv);
	}	
	else
	{
		ft_check_one_argument(argv);
		argument = ft_split(argv[1], ' ');
		create_stack_a(argc, argument);
	}
	return (0);
}
