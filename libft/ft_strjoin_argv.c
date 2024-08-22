/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_argv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:03:09 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/11 14:24:22 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calculate_len(char **strs, char *sep, int size)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (i < size)
	{
		count += ft_strlen(strs[i]);
		i++;
	}
	count += ((size - 1) * ft_strlen(sep)) + 1;
	return (count);
}

static char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin_argv(int size, char **strs, char *sep)
{
	int		i;
	char	*str;

	if (size == 0 || strs == NULL)
		return (NULL);
	str = malloc(calculate_len(strs, sep, size) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 1;
	*str = 0;
	while (i < size)
	{
		ft_strcat(str, strs[i]);
		if (i < size - 1)
			ft_strcat(str, sep);
		i++;
	}
	return (str);
}
