/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 04:18:33 by mateon            #+#    #+#             */
/*   Updated: 2025/10/12 12:36:38 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putstr(char *s)
{
	int	printed;

	printed = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (*s)
	{
		printed += ft_putchar(*s);
		s++;
	}
	return (printed);
}
