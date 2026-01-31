/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:50:01 by matnusko          #+#    #+#             */
/*   Updated: 2025/10/12 12:36:52 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

// #include <stdio.h>
// #include <string.h> // pour strchr

// char	*ft_strchr(const char *s, int c);

// int main(void)
// {
// 	const char *str = "Hello 42!";
// 	char *p1 = ft_strchr(str, 'o');
// 	char *p2 = strchr(str, 'o');

// 	printf("ft_strchr : %s\n", p1);
// 	printf("strchr    : %s\n", p2);

// 	// Test avec un caractère absent
// 	printf("ft_strchr (x) : %p\n", ft_strchr(str, 'x'));
// 	printf("strchr    (x) : %p\n", strchr(str, 'x'));
// 	return (0);
// }
