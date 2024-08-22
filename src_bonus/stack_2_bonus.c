/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:25:17 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/11 15:10:01 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	is_value_in_stack(int value, t_stack *stack)
{
	t_stack	*head;

	head = NULL;
	if (stack == NULL)
		return (0);
	if (stack->next == NULL && stack->prev == NULL)
	{
		if (stack->content == value)
			return (1);
		return (0);
	}
	while (stack != head)
	{
		if (head == NULL)
			head = stack;
		if (value == stack->content)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	stacksize(t_stack *stack)
{
	int		count;
	t_stack	*head;

	if (!stack)
		return (0);
	if (stack->next == NULL && stack->prev == NULL)
		return (1);
	head = NULL;
	count = 0;
	while (stack != head)
	{
		if (head == NULL)
			head = stack;
		count++;
		stack = stack->next;
	}
	return (count);
}

int	stackmin(t_stack *stack)
{
	int		min;
	t_stack	*head;

	if (!stack)
		return (0);
	min = stack->content;
	if (stack->next == NULL && stack->prev == NULL)
		return (min);
	head = NULL;
	while (stack != head)
	{
		if (head == NULL)
			head = stack;
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

int	stackmax(t_stack *stack)
{
	int		max;
	t_stack	*head;

	if (!stack)
		return (0);
	max = stack->content;
	if (stack->next == NULL && stack->prev == NULL)
		return (max);
	head = NULL;
	while (stack != head)
	{
		if (head == NULL)
			head = stack;
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}

int	is_sorted(t_stack	*stack)
{
	int		first_value;
	t_stack	*temp;

	temp = stack;
	if (temp->next == NULL)
		return (1);
	first_value = temp->content;
	temp = temp->next;
	while (temp->content != first_value)
	{
		if (temp->content < temp->prev->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}
