/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 04:18:44 by matnusko          #+#    #+#             */
/*   Updated: 2025/10/12 12:36:32 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putpointer(void *ptr)
{
	int					printed;

	if (!ptr)
		return (ft_putstr("(nil)"));
	printed = 0;
	printed += ft_putstr("0x");
	printed += ft_puthex((unsigned long long)ptr, 0);
	return (printed);
}
