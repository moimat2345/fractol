/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:21:54 by matnusko          #+#    #+#             */
/*   Updated: 2025/10/12 12:37:18 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;
	size_t	i;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while ((big[j + i] == little[j] && big[j + i])
			&& (little[j] && (i + j) < len))
		{
			j++;
			if (little[j] == 0)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}

// #include <stdio.h>

// // Déclare ton prototype ici
// char	*ft_strnstr(const char *big, const char *little, size_t len);

// int main(void)
// {
//     const char *text = "Hello 42 Bangkok";

//     printf("ft_strnstr (len=15): %s\n", ft_strnstr(text, "42", 15));
//     printf("ft_strnstr (len=5):  %s\n", ft_strnstr(text, "42", 5));
//     printf("ft_strnstr (empty):  %s\n", ft_strnstr(text, "", 5));

//     return 0;
// }