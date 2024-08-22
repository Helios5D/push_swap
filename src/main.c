/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:39:37 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/11 16:07:44 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void	printstacks(t_stacks *stacks)
// {
// 	t_stack	*head;

// 	ft_printf("\nStack A : \n");
// 	head = NULL;
// 	while (stacks->a && stacks->a != head)
// 	{
// 		if (head == NULL)
// 			head = stacks->a;
// 		ft_printf("%d\n", stacks->a->content);
// 		if (stacks->a->next != NULL)
// 			stacks->a = stacks->a->next;
// 	}
// 	ft_printf("\nStack B : \n");
// 	head = NULL;
// 	while (stacks->b && stacks->b != head)
// 	{
// 		if (head == NULL)
// 			head = stacks->b;
// 		ft_printf("%d\n", stacks->b->content);
// 		if (stacks->b->next != NULL)
// 			stacks->b = stacks->b->next;
// 	}
// 	ft_printf("\n");
// }

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
	t_stacks	stacks;

	if (ac == 1)
		return (1);
	if (!is_empty_string(av) || !create_stacks(&stacks, ac, av))
		return (ftd_printf(2, ERR), 1);
	stacks.a_size = stacksize(stacks.a);
	stacks.b_size = stacksize(stacks.b);
	if (!sort(&stacks))
		return (check_clear_stacks(&stacks), 1);
	return (check_clear_stacks(&stacks), 0);
}
