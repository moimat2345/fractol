/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 10:34:32 by matnusko          #+#    #+#             */
/*   Updated: 2025/10/12 12:37:03 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	result;

	i = 0;
	j = ft_strlen(dst);
	result = ft_strlen(src);
	if (size == 0)
		return (result);
	if (size <= j)
		return (result += size);
	else
		result += j;
	while (src[i] && j + 1 < size)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (result);
}

/*#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	char	a;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
	}
	a = n % 10 + '0';
	write(1, &a, 1);
}

int main() {
	char str1[] = "", str2[] = "hello",
		str3[] = "1337 42", str4[] = "Born to code";
	int	result;
	unsigned int	i;
	unsigned int	j;

	j = 10;
	i = 7;
	result = ft_strlcat(str1, str2, j);
	ft_putstr(str1);
	write(1, "\n", 1);
	ft_putnbr(result);
	write(1, "\n", 1);
	

	result = ft_strlcat(str3, str4, i);
	ft_putstr(str3);
	write(1, "\n", 1);
	ft_putnbr(result);
	write(1, "\n", 1);

	return 0;
}*/
