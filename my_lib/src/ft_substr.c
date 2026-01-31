/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:01:09 by matnusko          #+#    #+#             */
/*   Updated: 2025/10/12 12:37:24 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*rendu;

	if (!s)
		return (NULL);
	s_len = ft_strlen((char *)s);
	if (s_len <= start)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	rendu = (char *)malloc(len + 1);
	if (!rendu)
		return (NULL);
	ft_strlcpy(rendu, s + start, len + 1);
	return (rendu);
}

// #include <stdio.h>
// #include <stdlib.h>

// char	*ft_substr(char const *s, unsigned int start, size_t len);

// int	main(void)
// {
// 	char *str = "Hello 42Bangkok!";
// 	char *sub;

// 	// Test 1 : "Hello"
// 	sub = ft_substr(str, 0, 5);
// 	printf("Test 1 : \"%s\"\n", sub);
// 	free(sub);

// 	// Test 2 : "42"
// 	sub = ft_substr(str, 6, 2);
// 	printf("Test 2 : \"%s\"\n", sub);
// 	free(sub);

// 	// Test 3 : "Bangkok!"
// 	sub = ft_substr(str, 9, 20); // len trop grand → s_len - start = 8
// 	printf("Test 3 : \"%s\"\n", sub);
// 	free(sub);

// 	// Test 4 : start trop loin
// 	sub = ft_substr(str, 50, 5);
// 	printf("Test 4 : \"%s\"\n", sub);
// 	free(sub);

// 	return (0);
// }