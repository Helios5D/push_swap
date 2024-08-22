/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:57:07 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/11 10:39:35 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pb(t_stacks *stacks, int print)
{
	if (stackadd(&(stacks->b), unstack(&(stacks->a)), 1))
	{
		stacks->a_size -= 1;
		stacks->b_size += 1;
	}
	if (print)
		ft_printf("pb\n");
}

void	pa(t_stacks *stacks, int print)
{
	if (stackadd(&(stacks->a), unstack(&(stacks->b)), 1))
	{
		stacks->a_size += 1;
		stacks->b_size -= 1;
	}
	if (print)
		ft_printf("pa\n");
}
