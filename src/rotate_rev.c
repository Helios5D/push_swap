/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:48:28 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/11 14:40:00 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stacks *stacks, int print)
{
	if (stacks->a && stacks->a->next)
		stacks->a = stacks->a->prev;
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stacks *stacks, int print)
{
	stacks->b = stacks->b->prev;
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stacks *stacks, int print)
{
	if (stacks->a && stacks->a->next)
		stacks->a = stacks->a->prev;
	if (stacks->b && stacks->b->next)
		stacks->b = stacks->b->prev;
	if (print)
		ft_printf("rrr\n");
}
