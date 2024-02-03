/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:19:57 by manufern          #+#    #+#             */
/*   Updated: 2024/02/03 13:31:32 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

int main(int argc, char **argv)
{
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
		create_stack_a(argc, ft_split(argv[1], ' '));
		
	}
	return (0);
}
