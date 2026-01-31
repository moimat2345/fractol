/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 03:59:28 by matnusko          #+#    #+#             */
/*   Updated: 2025/10/12 12:36:22 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_puthex(unsigned long long num, int uppercase)
{
	char	*base;
	int		printed;

	printed = 0;
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (num >= 16)
		printed += ft_puthex(num / 16, uppercase);
	printed += ft_putchar(base[num % 16]);
	return (printed);
}
