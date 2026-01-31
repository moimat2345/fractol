/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 04:15:32 by matnusko          #+#    #+#             */
/*   Updated: 2025/10/12 12:36:47 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putunsigned(unsigned int n)
{
	int	printed;

	printed = 0;
	if (n >= 10)
		printed += ft_putunsigned(n / 10);
	printed += ft_putchar((n % 10) + '0');
	return (printed);
}
