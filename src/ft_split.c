/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:56:25 by manufern          #+#    #+#             */
/*   Updated: 2024/06/25 18:12:28 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

int	ft_string_count(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			|| (i == 0 && s[i] != c))
		{
			j ++;
		}
		i ++;
	}
	return (j);
}

int	ft_word_count(char const *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[i] != c && s[i])
	{
		j ++;
		i ++;
	}
	return (j);
}

char	**ft_free(char **aux)
{
	int	i;

	i = 0;
	while (aux[i] != NULL)
	{
		i++;
	}
	while (i > 0)
	{
		i --;
		free (aux[i]);
	}
	free(aux);
	return (NULL);
}

char	**ft_matrix(char **aux, char const *s, char c, int i)
{
	int	j;
	int	k;
	int	l;

	j = 0;
	while (s[i] != '\0')
	{
		k = 0;
		while (s[i] == c)
			i ++;
		if (s[i] == '\0')
		{
			aux[j] = NULL;
			return (aux);
		}
		aux[j] = (char *) malloc((ft_word_count(s, c, i) + 1) * sizeof(char));
		if (!aux[j])
			return (ft_free(aux));
		l = ft_word_count(s, c, i);
		while (k < l)
			aux[j][k ++] = s[i ++];
		aux[j ++][k] = '\0';
	}
	aux[j] = NULL;
	return (aux);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**aux;

	words = ft_string_count(s, c);
	if (words == 0)
	{
		write(1, "Error\n", 6);
		exit(0);
	}	
	aux = (char **)malloc((words + 1) * sizeof(char *));
	if (!aux)
		return (NULL);
	aux[words] = NULL;
	return (ft_matrix(aux, s, c, 0));
}
