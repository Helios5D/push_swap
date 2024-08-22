/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:49:02 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/08 09:56:24 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_printchar_fd(char c, int *count, int fd)
{
	write(fd, &c, 1);
	*count += 1;
}

void	ft_printstr_fd(char *str, int *count, int fd)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_printstr_fd("(null)", count, fd);
		return ;
	}
	while (str[i])
		i++;
	write(fd, str, i);
	*count += i;
}
