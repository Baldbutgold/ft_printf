/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 02:21:26 by ael-hadj          #+#    #+#             */
/*   Updated: 2024/12/16 02:21:28 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		written_size;
	int		i;
	int		count;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += 1;
			i++;
			if (format[i] == '%')
				count += ft_putchar('%');
			if (format[i] == 'c')
				count += ft_putchar(va_arg(args, int));
			if (format[i] == 's')
				count += ft_putstr(va_arg(args, char *));
			if (format[i] == 'd' || format[i] == 'i')
				count += ft_putnbr(va_arg(args, int));
			if (format[i] == 'u')
				count += ft_putnbr(va_arg(args, unsigned int));
			if (format[i] == 'p')
				count += ft_put_pointer((unsigned long)va_arg(args, void *));
			if (format[i] == 'x')
				count += ft_puthex(va_arg(args, unsigned int), 0);
			if (format[i] == 'X')
				count += ft_puthex(va_arg(args, unsigned int), 1);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	return (written_size);
}
