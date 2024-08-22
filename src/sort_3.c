/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:08:36 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/11 12:48:04 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_b_pos(t_stacks *stacks, int value)
{
	int		i;
	int		max;
	int		min;
	t_stack	*temp;

	i = 0;
	temp = stacks->b;
	max = stackmax(stacks->b);
	min = stackmin(stacks->b);
	while (i < stacks->b_size + 1)
	{
		if (value > max && temp->content == max)
			return (i);
		else if (value < min && temp->prev->content == min)
			return (i);
		if (value > temp->content && value < temp->prev->content)
			return (i);
		temp = temp->next;
		i++;
	}
	return (0);
}

int	find_a_pos(t_stacks *stacks, int value)
{
	int		i;
	int		max;
	int		min;
	t_stack	*temp;

	i = 0;
	temp = stacks->a;
	max = stackmax(stacks->a);
	min = stackmin(stacks->a);
	while (i < stacks->a_size + 1)
	{
		if (value > max && temp->prev->content == max)
			return (i);
		else if (value < min && temp->content == min)
			return (i);
		if (value < temp->content && value > temp->prev->content)
			return (i);
		temp = temp->next;
		i++;
	}
	return (0);
}
