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

int	ft_count_words(char **argument)
{
	int	i;

	i = 0;
	while (argument[i])
	{
		i ++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	char	**argument;
	int i;
	char *argu;
	char *aux;

	if (argc <= 1)
	{
		return (0);
	}
	i = 1;
	argu = malloc(2);
	argu[0] = ' ';
	argu[1] = '\0';
	/* printf("argc: %d\n", argc); */
	while (i < argc)
	{
		
		aux = ft_strjoin(argu, argv[i]);
		free(argu);
		argu = aux;
		aux = ft_strjoin(argu, " ");
		free(argu);
		argu = aux;
		i++;
	}
	i = 0;
	/* printf("argu: %s\n", argu); */
	
	/* printf("argument: %s\n", argument[7]); */
	/* printf("%d\n", ft_count_words(argument)); */
	/* comprobate_argument(ft_count_words(argument), argument);
	create_stack_a(ft_count_words(argument), argument); */

		argument = ft_split(argu, ' ');
		ft_check_one_argument(&argu);
		
		create_stack_a(argument);
	return (0);
}