/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:19:30 by matnusko          #+#    #+#             */
/*   Updated: 2025/10/12 12:36:50 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	free_tab(char **tab, int size)
{
	while (size > 0)
	{
		free(tab[size - 1]);
		size--;
	}
}

int	count_word(char const *str, char sep)
{
	size_t	i;
	int		word;

	i = 0;
	word = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		if (str[i])
		{
			word++;
			while (str[i] && str[i] != sep)
				i++;
		}
	}
	return (word);
}

int	when_next_sep(char const *str, char sep)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != sep)
		i++;
	return (i);
}

int	add_in_tab(char **rendu, char const *str, char sep, int word)
{
	int	j;
	int	i;
	int	size;

	i = 0;
	while (*str && i < word)
	{
		while (*str && *str == sep)
			str++;
		size = when_next_sep(str, sep);
		rendu[i] = (char *)malloc(sizeof(char) * (size + 1));
		if (!rendu[i])
			return (free_tab(rendu, i), 0);
		j = 0;
		while (j < size)
			rendu[i][j++] = *str++;
		rendu[i][j] = '\0';
		i++;
	}
	rendu[i] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**rendu;
	int		word;

	if (!s)
		return (NULL);
	word = count_word(s, c);
	rendu = (char **)malloc(sizeof(char *) * (word + 1));
	if (rendu == 0)
		return (NULL);
	if (!add_in_tab(rendu, s, c, word))
		return (free(rendu), NULL);
	return (rendu);
}
