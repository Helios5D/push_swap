/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftd_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:57:25 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/08 10:01:36 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	put_arg_fd(char format, va_list args, int *count, int fd)
{
	if (format == 'c')
		return (ft_printchar_fd(va_arg(args, int), count, fd), 1);
	else if (format == 'd' || format == 'i')
		return (ft_printnbr_fd(va_arg(args, int), count, fd), 1);
	else if (format == 'u')
		return (ft_printunsignednbr_fd(
				va_arg(args, unsigned int), count, fd), 1);
	else if (format == 's')
		return (ft_printstr_fd(va_arg(args, char *), count, fd), 1);
	else if (format == 'p')
		return (ft_printptr_fd(va_arg(args, unsigned long), count, fd), 1);
	else if (format == 'x')
		return (ft_printnbr_hex_fd(
				va_arg(args, unsigned int), 0, count, fd), 1);
	else if (format == 'X')
		return (ft_printnbr_hex_fd(
				va_arg(args, unsigned int), 1, count, fd), 1);
	else if (format == '%')
		return (ft_printchar_fd('%', count, fd), 1);
	else
		return (ft_printchar_fd('%', count, fd), -1);
}

int	ftd_printf(int fd, const char *str, ...)
{
	va_list			args;
	int				i;
	int				count;

	if (!str)
		return (-1);
	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			if (put_arg_fd(str[i + 1], args, &count, fd) == -1)
				i--;
			i++;
		}
		else if (str[i] == '%' && !str[i + 1])
			return (va_end(args), -1);
		else
			ft_printchar_fd(str[i], &count, fd);
		i++;
	}
	return (va_end(args), count);
}

// int	main(void)
// {
// 	ftd_printf(2, "\x1B[0;31mHello");
// }
