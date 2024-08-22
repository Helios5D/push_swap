/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:18:27 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/11 15:10:05 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	is_empty_string(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i][0] == '\0')
			return (0);
		i++;
	}
	return (1);
}

char	**join_tab(int ac, char **av)
{
	char	**tab;
	char	*str;

	str = ft_strjoin_argv(ac, av, " ");
	if (str == NULL)
		return (NULL);
	tab = ft_split(str, ' ');
	free(str);
	if (tab == NULL)
		return (NULL);
	return (tab);
}

int	is_string_number(char *str)
{
	int		i;
	long	number;
	int		sign;

	i = 0;
	number = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	if (ft_strlen(str + i) == 0)
		return (0);
	while (str[i] == '0')
		i++;
	if (ft_strlen(str + i) > 10)
		return (0);
	while (str[i] >= 48 && str[i] <= 57)
		number = number * 10 + (str[i++] - 48);
	if (number * sign > 2147483647 || number * sign < -2147483648 || str[i])
		return (0);
	return (1);
}

t_stack	*tab_to_stack(char **tab)
{
	t_stack	*stack;
	t_stack	*temp;
	int		i;
	int		number;

	if (tab == NULL)
		return (NULL);
	i = 0;
	stack = NULL;
	while (tab[i])
	{
		if (!is_string_number(tab[i]))
			return (free_char_tab(tab), stackclear(&stack), NULL);
		number = ft_atoi(tab[i]);
		if (i > 0 && is_value_in_stack(number, stack))
			return (free_char_tab(tab), stackclear(&stack), NULL);
		temp = stacknew(number);
		stackadd(&stack, temp, 0);
		i++;
	}
	return (free_char_tab(tab), stack);
}
