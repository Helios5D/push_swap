/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:42:02 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/11 15:36:24 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	is_instructions_valid(char **instructions)
{
	int	i;

	i = 0;
	while (instructions[i])
	{
		if (ft_strcmp(instructions[i], "sa") != 0
			&& ft_strcmp(instructions[i], "sb") != 0
			&& ft_strcmp(instructions[i], "ss") != 0
			&& ft_strcmp(instructions[i], "pa") != 0
			&& ft_strcmp(instructions[i], "pb") != 0
			&& ft_strcmp(instructions[i], "ra") != 0
			&& ft_strcmp(instructions[i], "rb") != 0
			&& ft_strcmp(instructions[i], "rr") != 0
			&& ft_strcmp(instructions[i], "rra") != 0
			&& ft_strcmp(instructions[i], "rrb") != 0
			&& ft_strcmp(instructions[i], "rrr") != 0)
			return (0);
		i++;
	}
	return (1);
}

void	execute_swap_push(t_stacks *stacks, char *instruction)
{
	if (ft_strcmp(instruction, "sa") == 0)
		sa(stacks, 0);
	else if (ft_strcmp(instruction, "sb") == 0)
		sb(stacks, 0);
	else if (ft_strcmp(instruction, "ss") == 0)
		ss(stacks, 0);
	else if (ft_strcmp(instruction, "pa") == 0)
		pa(stacks, 0);
	else if (ft_strcmp(instruction, "pb") == 0)
		pb(stacks, 0);
}

void	execute_rotate(t_stacks *stacks, char *instruction)
{
	if (ft_strcmp(instruction, "ra") == 0)
		ra(stacks, 0);
	else if (ft_strcmp(instruction, "rb") == 0)
		rb(stacks, 0);
	else if (ft_strcmp(instruction, "rr") == 0)
		rr(stacks, 0);
	else if (ft_strcmp(instruction, "rra") == 0)
		rra(stacks, 0);
	else if (ft_strcmp(instruction, "rrb") == 0)
		rrb(stacks, 0);
	else if (ft_strcmp(instruction, "rrr") == 0)
		rrr(stacks, 0);
}

void	execute_instructions(t_stacks *stacks, char **instructions)
{
	int	i;

	i = 0;
	while (instructions[i])
	{
		execute_swap_push(stacks, instructions[i]);
		execute_rotate(stacks, instructions[i]);
		i++;
	}
}
