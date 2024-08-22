/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:17:03 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/11 16:00:14 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	check_clear_stacks(t_stacks *stacks)
{
	if (stacks->a != NULL)
		stackclear(&(stacks->a));
	if (stacks->b != NULL)
		stackclear(&(stacks->b));
}

int	create_stacks(t_stacks *stacks, int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;

	a_stack = tab_to_stack(join_tab(ac, av));
	if (a_stack == NULL)
		return (stackclear(&a_stack), 0);
	b_stack = NULL;
	stacks->a = a_stack;
	stacks->b = b_stack;
	stacks->a_size = stacksize(stacks->a);
	stacks->b_size = 0;
	return (1);
}

int	main(int ac, char **av)
{
	char		**instructions;
	t_stacks	stacks;

	if (ac == 1)
		return (1);
	if (!is_empty_string(av) || !create_stacks(&stacks, ac, av))
		return (ftd_printf(2, ERR), 1);
	stacks.a_size = stacksize(stacks.a);
	stacks.b_size = stacksize(stacks.b);
	instructions = read_instructions(0);
	if (instructions == NULL || !is_instructions_valid(instructions))
		return (free_char_tab(instructions), check_clear_stacks(&stacks),
			ftd_printf(2, ERR), 1);
	execute_instructions(&stacks, instructions);
	free_char_tab(instructions);
	if (stacks.b_size == 0 && is_sorted(stacks.a))
		return (check_clear_stacks(&stacks), ft_printf("OK\n"), 0);
	return (check_clear_stacks(&stacks), ft_printf("KO\n", 1));
}
