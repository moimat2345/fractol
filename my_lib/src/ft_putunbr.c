/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 02:03:34 by matnusko          #+#    #+#             */
/*   Updated: 2025/10/12 12:36:41 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putunbr(unsigned int n)
{
	int	printed;

	printed = 0;
	if (n >= 10)
		printed += ft_putunbr(n / 10);
	printed += ft_putchar((n % 10) + '0');
	return (printed);
}
