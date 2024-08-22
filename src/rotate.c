/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:42:43 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/09 12:21:10 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stacks *stacks, int print)
{
	if (stacks->a && stacks->a->next)
		stacks->a = stacks->a->next;
	if (print)
		ft_printf("ra\n");
}

void	rb(t_stacks *stacks, int print)
{
	if (stacks->b && stacks->b->next)
		stacks->b = stacks->b->next;
	if (print)
		ft_printf("rb\n");
}

void	rr(t_stacks *stacks, int print)
{
	if (stacks->a && stacks->a->next)
		stacks->a = stacks->a->next;
	if (stacks->b && stacks->b->next)
		stacks->b = stacks->b->next;
	if (print)
		ft_printf("rr\n");
}
