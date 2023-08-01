/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:15:39 by huolivei          #+#    #+#             */
/*   Updated: 2023/02/06 11:05:06 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int nb, const char str)
{
	if (nb >= 16)
	{
		ft_puthex(nb / 16, str);
		ft_puthex(nb % 16, str);
	}
	else
	{
		if (nb <= 9)
			ft_putchar(nb + '0');
		else
		{
			if (str == 'x')
				ft_putchar(nb - 10 + 'a');
			if (str == 'X')
				ft_putchar(nb - 10 + 'A');
		}
	}
}

int	ft_printhex(unsigned int nb, const char str)
{
	if (nb == 0)
		return (ft_putchar('0'));
	else
		ft_puthex(nb, str);
	return (ft_nbsup16(nb));
}
