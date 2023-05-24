/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenglee <chenglee@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:37:56 by chenglee          #+#    #+#             */
/*   Updated: 2023/05/24 21:37:57 by chenglee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnum(int num, int *len)
{
	int	res;

	if (num < 10 && num > -10)
	{
		if (num < 0)
		{
			num *= -1;
			ft_putchar('-', len);
		}
		ft_putchar(num + 48, len);
		return ;
	}
	res = num % 10;
	if (res < 0)
		res *= -1;
	ft_putnum(num / 10, len);
	ft_putchar(res + 48, len);
}

void	ft_putunsigned_num(unsigned int num, int *len)
{
	if (num < 10)
	{
		ft_putchar(num + 48, len);
		return ;
	}
	ft_putnum(num / 10, len);
	ft_putchar((num % 10) + 48, len);
}

void	ft_puthex(long unsigned int num, int *len, const char *base)
{
	if (num < 16)
	{
		ft_putchar(base[num], len);
		return ;
	}
	ft_puthex(num / 16, len, base);
	ft_putchar(base[num % 16], len);
}

// void	ft_putlonghex(long unsigned int num, int *len, const char *base)
// {
// 	if (num < 16)
// 	{
// 		ft_putchar(base[num], len);
// 		return ;
// 	}
// 	ft_putlonghex(num / 16, len, base);
// 	ft_putchar(base[num % 16], len);
// }

void	ft_putpoint(void *ptr, int *len)
{
	uintptr_t	address;

	address = (uintptr_t)ptr;
	ft_putstr("0x", len);
	if (!ptr)
	{
		ft_putchar('0', len);
		return ;
	}
	ft_puthex(address, len, "0123456789abcdef");
}
