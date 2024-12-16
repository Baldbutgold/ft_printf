/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/144:46:52 by ael-hadj          #+#    #+#             */
/*   Updated: 2024/11/144:48:03 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
}

void	ft_putnbr(int n)
{
	if (n == INT_MIN)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + 48);
}

void	ft_puthex(unsigned int n, int is_upper)
{
	char	*low_hex = "0123456789abcdef";
	char	*upper_hex = "0123456789ABCDEF";

	if (is_upper == 1)
	{
		if (n == 0)
			return ;
		ft_puthex((n / 16), 1);
		ft_putchar(upper_hex[n % 16]);
	}
	else
	{
		if (n == 0)
			return ;
		ft_puthex((n / 16), 0);
		ft_putchar(low_hex[n % 16]);
	}
}
