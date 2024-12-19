/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:27:48 by ael-hadj          #+#    #+#             */
/*   Updated: 2024/12/19 09:28:14 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
	return (i);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == INT_MIN)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
		count++;
	}
	if (n > 9)
		count += ft_putnbr(n / 10);
	count += ft_putchar((n % 10) + 48);
	return (count);
}

int	ft_putunsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putnbr(n / 10);
	count += ft_putchar((n % 10) + 48);
	return (count);
}

int	ft_put_pointer(unsigned long pointer)
{
	int	count;

	count = 0;
	ft_putstr("0x");
	count = 2;
	count += ft_puthex((unsigned int)pointer, 0);
	return (count);
}

int	ft_puthex(unsigned int n, int is_upper)
{
	char	*low_hex = "0123456789abcdef";
	char	*upper_hex = "0123456789ABCDEF";
	int	count;

	if (is_upper == 1)
	{
		if (n == 0)
		{
			count += putchar('0');
			return (count);
		}
		ft_puthex((n / 16), 1);
		count += ft_putchar(upper_hex[n % 16]);
	}
	else
	{
		if (n == 0)
			return (count);
		ft_puthex((n / 16), 0);
		count += ft_putchar(low_hex[n % 16]);
	}
	return (count);
}
