/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:21:02 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/11 16:08:35 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	compute_cost(t_stacks *stacks, int	*cost, int a_pos, int b_pos)
{
	(*cost) = 1;
	if (a_pos > stacks->a_size / 2)
		(*cost) += stacks->a_size - a_pos;
	else
		(*cost) += a_pos;
	if (b_pos > stacks->b_size / 2)
		(*cost) += stacks->b_size - b_pos;
	else
		(*cost) += b_pos;
	if (a_pos > stacks->a_size / 2 && b_pos > stacks->b_size / 2)
		(*cost) -= ft_min(stacks->a_size - a_pos, stacks->b_size - b_pos);
	else if (a_pos < stacks->a_size / 2 && b_pos < stacks->b_size / 2)
		(*cost) -= ft_min(a_pos, b_pos);
}

void	optimize_operations(t_stacks *stacks, t_operations *operations)
{
	if (operations->ra > stacks->a_size / 2)
	{
		operations->rra = stacks->a_size - operations->ra;
		operations->ra = 0;
	}
	if (operations->rb > stacks->b_size / 2)
	{
		operations->rrb = stacks->b_size - operations->rb;
		operations->rb = 0;
	}
	if (operations->ra != 0 && operations->rb != 0)
	{
		operations->rr = ft_min(operations->ra, operations->rb);
		operations->ra -= operations->rr;
		operations->rb -= operations->rr;
	}
	else if (operations->rra != 0 && operations->rrb != 0)
	{
		operations->rrr = ft_min(operations->rra, operations->rrb);
		operations->rra -= operations->rrr;
		operations->rrb -= operations->rrr;
	}
}

void	compute_operations(t_stacks *stacks,
	t_operations *operations, int *cost)
{
	int	a_pos;
	int	b_pos;

	a_pos = 0;
	b_pos = 0;
	operations->cost = 0;
	while (a_pos < stacks->a_size)
	{
		b_pos = find_b_pos(stacks, stacks->a->content);
		compute_cost(stacks, cost, a_pos, b_pos);
		if (operations->cost == 0 || (*cost) < operations->cost)
		{
			operations->cost = (*cost);
			operations->ra = a_pos;
			operations->rb = b_pos;
			operations->rr = 0;
			operations->rra = 0;
			operations->rrb = 0;
			operations->rrr = 0;
			optimize_operations(stacks, operations);
		}
		if (stacks->a->next)
			stacks->a = stacks->a->next;
		a_pos++;
	}
}

void	execute_operations(t_stacks *stacks, t_operations *operations)
{
	int	i;

	i = 0;
	while (i++ < operations->rr)
		rr(stacks, 1);
	i = 0;
	while (i++ < operations->ra)
		ra(stacks, 1);
	i = 0;
	while (i++ < operations->rb)
		rb(stacks, 1);
	i = 0;
	while (i++ < operations->rrr)
		rrr(stacks, 1);
	i = 0;
	while (i++ < operations->rra)
		rra(stacks, 1);
	i = 0;
	while (i++ < operations->rrb)
		rrb(stacks, 1);
	pb(stacks, 1);
}

int	sort(t_stacks *stacks)
{
	t_operations	*operations;
	int				cost;
	int				i;

	sort_small_a(stacks);
	if (is_sorted(stacks->a))
		return (1);
	i = 0;
	pb(stacks, 1);
	pb(stacks, 1);
	operations = malloc(1 * sizeof(t_operations));
	if (operations == NULL)
		return (0);
	while (stacks->a_size > 3)
	{
		compute_operations(stacks, operations, &cost);
		execute_operations(stacks, operations);
		i++;
	}
	sort_small_a(stacks);
	if (stacks->a->content == stackmin(stacks->a))
		ra(stacks, 1);
	push_back(stacks);
	sort_rotate_a(stacks);
	return (free(operations), 1);
}
