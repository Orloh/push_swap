/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:58:05 by orhernan          #+#    #+#             */
/*   Updated: 2026/01/05 19:13:41 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	 print_arr(t_int_arr arr)
{
	int i = 0;
	if (!arr.data) 
	{
		printf("Result: NULL (Error detected succesfully)\n");
		return ;
	}
	printf("arr: ");
	while (i < arr.size)
	{
		printf("[%d] ", arr.data[i]);
		i++;
	}
	printf("\nSize: %d\n", arr.size);
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

int	main(void)
{
	t_int_arr	res;
	int	i;

	// Test 1
	printf("--- TEST 1: Multiple Args (1 42 -5) ---\n");
	char	*test1[] = {"push_swap", "1", "42", "-5", NULL};
	res = ft_parse_args(4, test1);
	print_arr(res);
	ft_free_int_arr(&res);

	// Test2
	printf("\n--- TEST 2: Quoted String (\"100 200 300 1000\") ---\n");
	char	*test2[] = {"push_swap", "100 200 300 1000", NULL};
	res = ft_parse_args(2, test2);
	print_arr(res);
	ft_free_int_arr(&res);
	
	// Test 3
	printf("\n--- TEST 3: Overflow (Should be NULL) ---\n");
	char	*test3[] = {"push_swap", "2147483648", NULL};
	res = ft_parse_args(2, test3);
	print_arr(res);
	ft_free_int_arr(&res);

	// Test 4
	printf("\n--- TEST 4: Alpha chars (Should be NULL) ---\n");
	char	*test4[] = {"push_swap", "12", "34a", "56", NULL};
	res = ft_parse_args(2, test4);
	print_arr(res);
	ft_free_int_arr(&res);

	// Test 5
	printf("\n--- TEST 5: Random Sort (500 integers) ---\n");	
	res.size = 500;
	res.data = (int *)ft_calloc(res.size, sizeof(int));	
	i = 0;
	if (!res.data)
	{
		res.size = 0;
		return (1);
	}
	srand(time(NULL));
	while (i < res.size)
	{
		res.data[i] = ((rand() << 16 | rand()));
		i++;
	}
	printf("First 5 unsorted: %d %d %d %d %d\n", res.data[0], res.data[1], res.data[2], res.data[3], res.data[4]);
	ft_sort_array(&res);
	printf("First 5 sorted: %d %d %d %d %d\n", res.data[0], res.data[1], res.data[2], res.data[3], res.data[4]);
	ft_free_int_arr(&res);

	// Test 6
	printf("\n--- TEST 6: Ordered Array (500 integers) ---\n");	
	res.size = 5;
	res.data = (int *)ft_calloc(res.size, sizeof(int));
	if (!res.data)
	{
		res.size = 0;
		return (1);
	}
	i = -1;
	while (++i < 5)
		res.data[i] = i + 1;
	ft_sort_array(&res);
	print_arr(res);
	ft_free_int_arr(&res);

	// Test 7
	printf("\n--- TEST 7: Reversed Array (500 integers) ---\n");	
	res.size = 5;
	res.data = (int *)ft_calloc(res.size, sizeof(int));
	if (!res.data)
	{
		res.size = 0;
		return (1);
	}
	i = 5;
	while (--i >= 0)
		res.data[i] = i + 1;
	ft_sort_array(&res);
	print_arr(res);
	ft_free_int_arr(&res);

	// Test 8
	printf("\n--- TEST 8: Stack Init (Scrambled: 42 1 -5 10) ---\n");
	char	*test8[] = {"push_swap", "42", "1", "-5", "10", NULL};
	res = ft_parse_args(5, test8);
	t_list	*stack_a = ft_init_stack(&res);
	print_stack("A", stack_a);
	ft_lstclear(&stack_a, free);
	ft_free_int_arr(&res);

	// Test 9
	printf("\n--- TEST 9: Stack Init (Duplicates/Negative Mix) ---\n");
	char	*test9[] = {"push_swap", "100", "-100", "0", "50", NULL};
	res = ft_parse_args(5, test9);
	stack_a = ft_init_stack(&res);
	print_stack("A", stack_a);
	ft_lstclear(&stack_a, free);
	ft_free_int_arr(&res);

	// Test 10
	printf("\n--- TEST 10: Stack Init (Single Element) ---\n");
	char	*test10[] = {"push_swap", "42", NULL};
	res = ft_parse_args(2, test10);
	stack_a = ft_init_stack(&res);
	print_stack("A", stack_a);
	ft_lstclear(&stack_a, free);
	ft_free_int_arr(&res);

	// Test 11
	printf("\n--- TEST 11: Stack Init (Duplicates) 1 5 2 5 ---\n");
	char	*test11[] = {"push_swap", "1", "5", "2", "5", NULL};
	res = ft_parse_args(5, test11);
	stack_a = ft_init_stack(&res);
	if (stack_a == NULL)
		printf("Result: NULL (Duplicates detected succesfully)\n");
	else
	{
		printf("Error: Stack initialized despite duplicates!\n");
		print_stack("DUP", stack_a);
		ft_lstclear(&stack_a, free);
	}
	ft_free_int_arr(&res);

	printf("\n--- OPERATION TESTING ---\n");	
	t_list	*a = NULL;
	t_list	*b = NULL;

	// Test 8
	printf("\n--- TEST 9: Unit Test Push (pa/pb)  ---\n");
	ft_lstadd_back(&a, ft_lstnew(ft_new_content(10, 0)));
	ft_lstadd_back(&a, ft_lstnew(ft_new_content(20, 1)));
	
	printf("Initial State:\n");
	print_stack("A", a);
	print_stack("B", b);

	// Test pb: A -> B
	printf("\nAction: pb\n");
	pb(&a, &b);
	print_stack("A", a);
	print_stack("B", b);

	// Test pa: B -> A
	printf("\nAction: pa\n");
	pa(&a, &b);
	print_stack("A", a);
	print_stack("B", b);

	// Test Edge case: pa on empty stack
	printf("\nAction: pa on empty B stack (Should do nothing)\n");
	pa(&a, &b);
	print_stack("A", a);
	print_stack("B", b);

	ft_lstclear(&a, free);
	ft_lstclear(&b, free);

	return (0);
}
