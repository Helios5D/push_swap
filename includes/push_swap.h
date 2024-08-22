/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:42:19 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/11 16:01:59 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Includes //

# include "../libft/libft.h"

// Defines //

# define ERR "Error\n"

// Structures //

// Structures

typedef struct s_operations
{
	int			cost;
	int			ra;
	int			rb;
	int			rr;
	int			rra;
	int			rrb;
	int			rrr;
}	t_operations;

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	int		a_size;
	int		b_size;
}	t_stacks;

// Prototypes //

// Stack //
int		stackadd(t_stack **lst, t_stack *new, int back);
t_stack	*unstack(t_stack **stack);
void	stackclear(t_stack **lst);
t_stack	*stacknew(int content);
int		is_value_in_stack(int value, t_stack *lst);
int		stacksize(t_stack *lst);
int		stackmin(t_stack *stack);
int		stackmax(t_stack *stack);
int		is_sorted(t_stack	*stack);
void	printstacks(t_stacks *stacks);

// Parsing //
int		is_empty_string(char **av);
t_stack	*tab_to_stack(char **tab);
char	**join_tab(int ac, char **av);

// Operations //
// push.c
void	pb(t_stacks *stacks, int print);
void	pa(t_stacks *stacks, int print);
// rotate.c
void	ra(t_stacks *stacks, int print);
void	rb(t_stacks *stacks, int print);
void	rr(t_stacks *stacks, int print);
// rotate_rev.c
void	rra(t_stacks *stacks, int print);
void	rrb(t_stacks *stacks, int print);
void	rrr(t_stacks *stacks, int print);
// swap.c
void	sa(t_stacks *stacks, int print);
void	sb(t_stacks *stacks, int print);
void	ss(t_stacks *stacks, int print);

// Sorting //
// sort_1.c
void	compute_cost(t_stacks *stacks, int	*cost, int a_pos, int b_pos);
void	optimize_operations(t_stacks *stacks, t_operations *operations);
void	compute_operations(t_stacks *stacks,
			t_operations *operations, int *cost);
void	execute_operations(t_stacks *stacks, t_operations *operations);
int		sort(t_stacks *stacks);
// sort_2.c
int		sort_a_three(t_stacks *stacks);
void	sort_small_a(t_stacks *stacks);
void	push_back(t_stacks *stacks);
void	sort_rotate_a(t_stacks *stacks);
// sort_3.c
int		find_a_pos(t_stacks *stacks, int value);
int		find_b_pos(t_stacks *stacks, int value);

#endif
