/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:19:59 by matnusko          #+#    #+#             */
/*   Updated: 2025/10/12 12:33:54 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*rendu;
	size_t	total;

	total = nmemb * size;
	if (total == 0)
		return (malloc(0));
	else if ((long) nmemb < 0 || (long) size < 0)
		return (NULL);
	rendu = (void *)malloc(total);
	if (!rendu)
		return (0);
	ft_bzero(rendu, total);
	return ((void *)rendu);
}

// #include <stdio.h>
// #include <stdlib.h>

// void	*ft_calloc(size_t nmemb, size_t size);

// int main(void)
// {
//     int *arr1 = (int *)ft_calloc(5, sizeof(int));
//     int *arr2 = (int *)calloc(5, sizeof(int));

//     printf("ft_calloc : ");
//     for (int i = 0; i < 5; i++)
//         printf("%d ", arr1[i]);   // doit afficher 0 0 0 0 0
//     printf("\n");

//     printf("calloc    : ");
//     for (int i = 0; i < 5; i++)
//         printf("%d ", arr2[i]);   // doit afficher 0 0 0 0 0
//     printf("\n");

//     free(arr1);
//     free(arr2);
//     return 0;
// }
