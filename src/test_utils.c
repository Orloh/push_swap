/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:16:49 by orhernan          #+#    #+#             */
/*   Updated: 2026/01/27 18:33:23 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	 print_arr(t_int_arr arr)
{
	int i = 0;
	if (!arr.data) 
	{
		ft_printf("Result: NULL (Error detected succesfully)\n");
		return ;
	}
	ft_printf("arr: ");
	while (i < arr.size)
	{
		ft_printf("[%d] ", arr.data[i]);
		i++;
	}
	ft_printf("\nSize: %d\n", arr.size);
}

t_node_content	*ft_new_content(int val, int rank)
{
	t_node_content *c = malloc(sizeof(t_node_content));
	if (!c) return (NULL);
	c->value = val;
	c->rank = rank;
	return (c);
}

void	print_stack(char *name, t_list *s)
{
	printf("Stack %s (Value [Rank]):", name);
	if (!s)
		printf("(empty)");
	while (s)
	{
		t_node_content *c = (t_node_content *)s->content;
		printf("%d [%d] -> ", c->value, c->rank);
		s = s->next;
	}
	printf("NULL\n");
}

void	assert_test(int condition, char *description)
{
	if (condition)
		printf(GREEN "[PASS] %s\n" RESET, description);
	else
		printf(RED "[FAIL] %s\n" RESET, description);
}

t_list	*create_test_stack(int *values, int size)
{
	t_int_arr	tmp;
	t_list	*stack;

	tmp.data = values;
	tmp.size = size;
	stack = ft_init_stack(&tmp);
	return (stack);
}

void	clear_stacks(t_stacks *stacks)
{
	if (stacks->a) ft_lstclear(&(stacks->a), free);
	if (stacks->b) ft_lstclear(&(stacks->b), free);
}

void	test_big_sort_silent(int *arr, int size, char *msg)
{
	t_stacks	*stacks;
	int		fd_null;
	int		stdout_backup;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks) return ;
	stacks->a = create_test_stack(arr,size);
	stacks->b = NULL;

	stdout_backup = dup(STDOUT_FILENO);
	fd_null = open("/dev/null", O_WRONLY);
	dup2(fd_null, STDOUT_FILENO);

	ft_big_sort(stacks);

	dup2(stdout_backup, STDOUT_FILENO);
	close(fd_null);
	close(stdout_backup);

	assert_test(ft_is_sorted_stack(stacks->a) && ft_lstsize(stacks->a) == size, msg);
	clear_stacks(stacks);
	free(stacks);
}
