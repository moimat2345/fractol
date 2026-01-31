/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:37:39 by matnusko          #+#    #+#             */
/*   Updated: 2025/10/12 12:33:17 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	int		result;
	char	*str;

	i = 0;
	sign = 1;
	result = 0;
	str = (char *)nptr;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result = result + str[i] - '0';
		i++;
	}
	return (result * sign);
}

// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
//     printf("ft_atoi(\"42\")        = %d\n", ft_atoi("42"));
//     printf("atoi(\"42\")           = %d\n", atoi("42"));

//     printf("ft_atoi(\"   -123abc\")= %d\n", ft_atoi("   -123abc"));
//     printf("atoi(\"   -123abc\")   = %d\n", atoi("   -123abc"));

//     printf("ft_atoi(\"+7\")        = %d\n", ft_atoi("+7"));
//     printf("atoi(\"+7\")           = %d\n", atoi("+7"));

//     printf("ft_atoi(\"abc123\")    = %d\n", ft_atoi("abc123"));
//     printf("atoi(\"abc123\")       = %d\n", atoi("abc123"));

//     return 0;
// }