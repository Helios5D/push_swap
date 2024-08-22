/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:10:36 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/11 15:10:02 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	stackadd(t_stack **stack, t_stack *new, int back)
{
	if (new == NULL || stack == NULL)
		return (0);
	if ((*stack) != NULL)
	{
		if ((*stack)->next == NULL && (*stack)->prev == NULL)
		{
			(*stack)->next = new;
			(*stack)->prev = new;
			new->next = (*stack);
			new->prev = (*stack);
		}
		else
		{
			new->next = (*stack);
			new->prev = (*stack)->prev;
			(*stack)->prev->next = new;
			(*stack)->prev = new;
		}
		if (back != 0)
			(*stack) = new;
	}
	else
		(*stack) = new;
	return (1);
}

t_stack	*unstack(t_stack **stack)
{
	t_stack	*top;

	top = (*stack);
	if (!stack || !(*stack))
		return (NULL);
	if ((*stack)->next && (*stack)->next == (*stack)->prev)
	{
		(*stack)->next->next = NULL;
		(*stack)->next->prev = NULL;
	}
	else if ((*stack)->next)
	{
		(*stack)->prev->next = (*stack)->next;
		(*stack)->next->prev = (*stack)->prev;
	}
	*stack = (*stack)->next;
	top->next = NULL;
	top->prev = NULL;
	return (top);
}

void	stackclear(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*head;

	if (!stack || !(*stack))
		return ;
	if ((*stack)->next == NULL && (*stack)->prev == NULL)
	{
		free(*stack);
		*stack = NULL;
		return ;
	}
	head = NULL;
	while (*stack != head)
	{
		if (head == NULL)
			head = *stack;
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

t_stack	*stacknew(int content)
{
	t_stack	*elem;

	elem = malloc(1 * sizeof(t_stack));
	if (elem == NULL)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}
