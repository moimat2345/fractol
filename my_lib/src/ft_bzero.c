/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 20:01:15 by matnusko          #+#    #+#             */
/*   Updated: 2025/10/12 12:33:47 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)s;
	while (i < n)
	{
		temp[i] = 0;
		i++;
	}
}

// #include <stdio.h>
// #include <string.h>

// void printArray(int arr[], int n)
// {
//    for (int i=0; i<n; i++)
//       printf("%d ", arr[i]);
// }

// int main()
// {
//     int n = 10;
//     int arr[n];
// 	int n2 = 10;
//     int arr2[n];

//     // Fill whole array with 0.
//     memset(arr, sizeof(arr));
//     printf("Real memset()\n");
//     printArray(arr, n);

// 	ft_memset(arr2, sizeof(arr2));
//     printf("\nMy memset()\n");
//     printArray(arr2, n2);

//     return 0;
// }