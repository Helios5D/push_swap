/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:39:44 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/11 13:04:54 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sort_a_three(t_stacks *stacks)
{
	if (is_sorted(stacks->a))
		return (1);
	if (is_sorted(stacks->a->next))
		return (ra(stacks, 1), 1);
	if (is_sorted(stacks->a->prev))
		return (rra(stacks, 1), 1);
	sa(stacks, 1);
	if (is_sorted(stacks->a))
		return (1);
	if (is_sorted(stacks->a->next))
		return (ra(stacks, 1), 1);
	if (is_sorted(stacks->a->prev))
		return (rra(stacks, 1), 1);
	return (0);
}

void	sort_small_a(t_stacks *stacks)
{
	if (stacks->a_size == 2)
	{
		if (stacks->a->content > stacks->a->next->content)
			sa(stacks, 1);
	}
	else if (stacks->a_size == 3)
		sort_a_three(stacks);
}

void	optimize_rotate_a(t_stacks *stacks, int index)
{
	int	i;

	i = 0;
	if (index < stacks->a_size / 2)
	{
		while (i < index)
		{
			ra(stacks, 1);
			i++;
		}
	}
	else
	{
		index = stacks->a_size - index;
		while (i < index)
		{
			rra(stacks, 1);
			i++;
		}
	}
}

void	push_back(t_stacks *stacks)
{
	int		max;
	int		min;

	max = stackmax(stacks->a);
	min = stackmin(stacks->a);
	while (stacks->b != NULL)
	{
		if (stacks->b->content < min && stacks->a->content == min)
		{
			min = stacks->b->content;
			pa(stacks, 1);
		}
		else if (stacks->b->content > max && stacks->a->prev->content == max)
		{
			max = stacks->b->content;
			pa(stacks, 1);
		}
		else if (stacks->b->content < stacks->a->content
			&& stacks->b->content > stacks->a->prev->content)
			pa(stacks, 1);
		else
			optimize_rotate_a(stacks, find_a_pos(stacks, stacks->b->content));
	}
}

void	sort_rotate_a(t_stacks *stacks)
{
	int		min;
	int		min_index;
	t_stack	*temp;

	temp = stacks->a;
	min = stackmin(temp);
	min_index = 0;
	while (temp->content != min)
	{
		temp = temp->next;
		min_index++;
	}
	if (min_index <= stacks->a_size / 2)
	{
		while (stacks->a->content != min)
			ra(stacks, 1);
	}
	else
	{
		while (stacks->a->content != min)
			rra(stacks, 1);
	}
}
