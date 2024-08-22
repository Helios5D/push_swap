/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 07:57:45 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/08 10:00:13 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_printnbr_hex_fd(unsigned int nbr, int is_upper, int *count, int fd)
{
	unsigned int	digits;

	digits = 16;
	if (is_upper)
	{
		if (nbr >= digits)
			ft_printnbr_hex_fd((nbr / digits), is_upper, count, fd);
		ft_printchar_fd("0123456789ABCDEF"[nbr % digits], count, fd);
	}
	else
	{
		if (nbr >= digits)
			ft_printnbr_hex_fd((nbr / digits), is_upper, count, fd);
		ft_printchar_fd("0123456789abcdef"[nbr % digits], count, fd);
	}
}

void	ft_printnbr_fd(int n, int *count, int fd)
{
	if (n == -2147483648)
		ft_printstr_fd("-2147483648", count, fd);
	else
	{
		if (n < 0)
		{
			ft_printchar_fd(45, count, fd);
			n = -n;
		}
		if (n >= 10)
			ft_printnbr_fd(n / 10, count, fd);
		ft_printchar_fd(48 + n % 10, count, fd);
	}
}

void	ft_printunsignednbr_fd(unsigned int n, int *count, int fd)
{
	if (n >= 10)
		ft_printunsignednbr_fd(n / 10, count, fd);
	ft_printchar_fd(48 + n % 10, count, fd);
}

void	ft_printptr_rec_fd(unsigned long nbr, char *base, int *count, int fd)
{
	unsigned long	digits;

	digits = 16;
	if (nbr >= digits)
		ft_printptr_rec_fd((nbr / digits), base, count, fd);
	ft_printchar_fd(base[nbr % digits], count, fd);
}

void	ft_printptr_fd(unsigned long ptr, int *count, int fd)
{
	if (ptr == 0)
		ft_printstr_fd("(nil)", count, fd);
	else
	{
		ft_printstr_fd("0x", count, fd);
		ft_printptr_rec_fd(ptr, "0123456789abcdef", count, fd);
	}
}
