/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:19:40 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/11 15:10:00 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	sa(t_stacks *stacks, int print)
{
	t_stack	*temp_prev;
	t_stack	*temp_next;

	if (stacks->a && stacks->a->next)
	{
		temp_prev = stacks->a->prev;
		temp_next = stacks->a->next->next;
		if (stacks->a->next == stacks->a->prev)
			stacks->a = stacks->a->next;
		else
		{
			stacks->a->prev->next = stacks->a->next;
			stacks->a->next->next->prev = stacks->a;
			stacks->a->prev = stacks->a->next;
			stacks->a->next->next = stacks->a;
			stacks->a->next->prev = temp_prev;
			stacks->a->next = temp_next;
			stacks->a = stacks->a->prev;
		}
	}
	if (print)
		ft_printf("sa\n");
}

void	sb(t_stacks *stacks, int print)
{
	t_stack	*temp_prev;
	t_stack	*temp_next;

	temp_prev = NULL;
	temp_next = NULL;
	if (stacks->b && stacks->b->next)
	{
		temp_prev = stacks->b->prev;
		temp_next = stacks->b->next->next;
		if (stacks->b->next == stacks->b->prev)
			stacks->b = stacks->b->next;
		else
		{
			stacks->b->prev->next = stacks->b->next;
			stacks->b->next->next->prev = stacks->b;
			stacks->b->prev = stacks->b->next;
			stacks->b->next->next = stacks->b;
			stacks->b->next->prev = temp_prev;
			stacks->b->next = temp_next;
			stacks->b = stacks->b->prev;
		}
	}
	if (print)
		ft_printf("sb\n");
}

void	ss(t_stacks *stacks, int print)
{
	sa(stacks, 0);
	sb(stacks, 0);
	if (print)
		ft_printf("ss\n");
}
