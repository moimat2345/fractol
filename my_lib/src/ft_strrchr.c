/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:41:07 by matnusko          #+#    #+#             */
/*   Updated: 2025/10/12 12:37:20 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*der;

	der = 0;
	if (!(char)c)
		return ((char *)s);
	while (*s)
	{
		if (*s == (char)c)
			der = s;
		s++;
	}
	return ((char *)der);
}

// #include <stdio.h>
// #include <string.h>

// char	*ft_strrchr(const char *s, int c);

// int main(void)
// {
//     const char *txt = "Hello world !";
//     char *p1 = ft_strrchr(txt, 'o');
//     char *p2 = strrchr(txt, 'o');

//     printf("ft_strrchr : %s\n", p1);
//     printf("strrchr    : %s\n", p2);

//     // test avec un caractère absent
//     printf("ft_strrchr (x) : %p\n", ft_strrchr(txt, 'x'));
//     printf("strrchr    (x) : %p\n", strrchr(txt, 'x'));

//     return (0);
// }
