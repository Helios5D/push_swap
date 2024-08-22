/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:35:53 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/11 16:04:00 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = ft_strlen(dest);
	while (src[i] && i < nb)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = 0;
	return (dest);
}

char	*ft_realloc(char *str, int size)
{
	char	*new_str;
	int		str_size;

	if (str == NULL)
		str_size = 0;
	else
		str_size = ft_strlen(str);
	new_str = malloc(((str_size + size + 1) * sizeof(char)));
	if (!new_str)
		return (free(str), NULL);
	new_str[0] = '\0';
	ft_strncat(new_str, str, str_size);
	return (free(str), new_str);
}

char	**read_instructions(int fd)
{
	int		ret;
	char	buff[1025];
	char	*str;
	char	**instructions;

	ret = read(fd, buff, 1024);
	str = malloc(1 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	while (ret > 0)
	{
		buff[ret] = 0;
		str = ft_realloc(str, ret);
		if (!str || ret < 0)
			return (free(str), NULL);
		ft_strncat(str, buff, ret);
		ret = read(fd, buff, 1024);
	}
	instructions = ft_split(str, '\n');
	free(str);
	if (instructions == NULL)
		return (NULL);
	return (instructions);
}
