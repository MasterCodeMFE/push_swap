/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:19:57 by manufern          #+#    #+#             */
/*   Updated: 2024/02/09 17:26:16 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void at_exit(void)
{
	system("leaks -q push_swap");
}

int ft_count_words(char **argument)
{
	int	i;

		i = 0;
	while (argument[i])
	{
		i ++;
	}
	return (i);
}

int main(int argc, char **argv)
{
	/* atexit(at_exit); */
	char **argument;
	if (argc <= 1)
	{
		printf ("no hay argumentos");
		return (-1);
	}
	/* printf ("hay argumentos\n"); */
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