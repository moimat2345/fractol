/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:12:26 by matnusko          #+#    #+#             */
/*   Updated: 2025/10/12 12:36:55 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s)
{
	char	*rendu;
	int		i;

	i = 0;
	rendu = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (rendu == 0)
		return (0);
	while (s[i])
	{
		rendu[i] = s[i];
		i++;
	}
	rendu[i] = '\0';
	return (rendu);
}
