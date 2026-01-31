/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 21:28:44 by mateon            #+#    #+#             */
/*   Updated: 2025/10/12 12:37:22 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	if (!set)
		return (0);
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*rendu;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && in_set(s1[start], set))
		start++;
	while (start < end && in_set(s1[end - 1], set))
		end--;
	rendu = (char *)malloc((end - start) + 1);
	if (!rendu)
		return (NULL);
	i = 0;
	while (start + i < end)
	{
		rendu[i] = s1[start + i];
		i++;
	}
	rendu[i] = '\0';
	return (rendu);
}
