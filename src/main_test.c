/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:58:05 by orhernan          #+#    #+#             */
/*   Updated: 2026/01/19 18:43:26 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//--- COLOR MACROS ---
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

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

void	assert_test(int condition, char *description)
{
	if (condition)
		printf(GREEN "[PASS] %s\n" RESET, description);
	else
		printf(RED "[FAIL] %s\n" RESET, description);
}

t_list	*create_test_stack(int *values, int size)
{
	t_list	*stack = NULL;
	for (int i=0; i < size; i++)
		ft_lstadd_back(&stack, ft_lstnew(ft_new_content(values[i], i)));
	return stack;
}

void clear_stacks(t_stacks *stacks)
{
	if (stacks->a) ft_lstclear(&(stacks->a), free);
	if (stacks->b) ft_lstclear(&(stacks->b), free);
}

int	main(void)
{
	t_int_arr	res;
	int	i;

	printf(YELLOW "--- PARSING TESTS  ---\n" RESET);
	// Test 1
	printf(YELLOW "\n--- TEST 1: Multiple Args (1 42 -5) ---\n" RESET);
	char	*test1[] = {"push_swap", "1", "42", "-5", NULL};
	res = ft_parse_args(4, test1);
	print_arr(res);
	assert_test(res.data != NULL && res.size == 3, "Args parsing");
	ft_free_int_arr(&res);

	// Test2
	printf(YELLOW "\n--- TEST 2: Quoted String (\"100 200 300 1000\") ---\n" RESET);
	char	*test2[] = {"push_swap", "100 200 300 1000", NULL};
	res = ft_parse_args(2, test2);
	print_arr(res);
	assert_test(res.data != NULL && res.size == 4, "Spliting args parsing");
	ft_free_int_arr(&res);
	
	// Test 3
	printf(YELLOW "\n--- TEST 3: Overflow (Should be NULL) ---\n" RESET);
	char	*test3[] = {"push_swap", "2147483648", NULL};
	res = ft_parse_args(2, test3);
	print_arr(res);
	assert_test(res.data == NULL, "Overflow test");
	ft_free_int_arr(&res);

	// Test 4
	printf(YELLOW "\n--- TEST 4: Alpha chars (Should be NULL) ---\n" RESET);
	char	*test4[] = {"push_swap", "12", "34a", "56", NULL};
	res = ft_parse_args(4, test4);
	print_arr(res);
	assert_test(res.data == NULL, "Invalid input test");
	ft_free_int_arr(&res);

	printf(YELLOW "\n--- SORTING INT ARRAY TESTS  ---\n" RESET);
	// Test 5
	printf(YELLOW "\n--- TEST 5: Random Sort (500 integers) ---\n" RESET);	
	res.size = 500;
	res.data = (int *)ft_calloc(res.size, sizeof(int));	
	i = 0;
	if (!res.data)
	{
		res.size = 0;
		printf(RED "[FAIL] Malloc error in Test 5 setup.\n");
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
	assert_test(ft_is_sorted(&res), "Random sort test");
	ft_free_int_arr(&res);

	// Test 6
	printf(YELLOW "\n--- TEST 6: Ordered Array (5 integers) ---\n" RESET);	
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
	assert_test(ft_is_sorted(&res), "Ordered array test");
	ft_free_int_arr(&res);

	// Test 7
	printf(YELLOW "\n--- TEST 7: Reversed Array (5 integers) ---\n" RESET);	
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
	assert_test(ft_is_sorted(&res), "Reversed array test");
	ft_free_int_arr(&res);

	printf(YELLOW "\n--- STACK INITIALIZATION TESTS---\n" RESET);
	// Test 8
	printf(YELLOW "\n--- TEST 8: Stack Init (Scrambled: 42 1 -5 10) ---\n" RESET);
	char	*test8[] = {"push_swap", "42", "1", "-5", "10", NULL};
	res = ft_parse_args(5, test8);
	t_list	*stack_a = ft_init_stack(&res);
	print_stack("A", stack_a);
	assert_test(stack_a != NULL && ft_lstsize(stack_a) == 4, "Stack initialization test.");
	ft_lstclear(&stack_a, free);
	ft_free_int_arr(&res);

	// Test 9
	printf(YELLOW "\n--- TEST 9: Stack Init (Duplicates/Negative Mix) ---\n" RESET);
	char	*test9[] = {"push_swap", "100", "-100", "0", "50", NULL};
	res = ft_parse_args(5, test9);
	stack_a = ft_init_stack(&res);
	print_stack("A", stack_a);
	assert_test(stack_a != NULL && ft_lstsize(stack_a) == 4, "Stack initialization with negatives test.");
	ft_lstclear(&stack_a, free);
	ft_free_int_arr(&res);


	printf(YELLOW "\n--- Stack Init (Single Element) ---\n" RESET);
	// Test 10
	printf(YELLOW "\n--- TEST 10: Stack Init (Single Element) ---\n" RESET);
	char	*test10[] = {"push_swap", "42", NULL};
	res = ft_parse_args(2, test10);
	stack_a = ft_init_stack(&res);
	print_stack("A", stack_a);
	assert_test(stack_a != NULL && ft_lstsize(stack_a) == 1, "Single element stack initialization test.");
	ft_lstclear(&stack_a, free);
	ft_free_int_arr(&res);

	// Test 11
	printf(YELLOW "\n--- TEST 11: Stack Init (Duplicates) 1 5 2 5 ---\n" RESET);
	char	*test11[] = {"push_swap", "1", "5", "2", "5", NULL};
	res = ft_parse_args(5, test11);
	stack_a = ft_init_stack(&res);
	print_stack("A", stack_a);
	assert_test(stack_a == NULL, "Stack initialization with duplicates test.");
	if (stack_a) ft_lstclear(&stack_a, free);
	ft_free_int_arr(&res);

	printf(YELLOW "\n--- OPERATION TESTS ---\n" RESET);	
	t_stacks	*stacks = malloc(sizeof(t_stacks));
	if (!stacks)
	{
		printf(RED "[FAIL] Malloc error for operation testing" RESET);
		return (1);
	}

	stacks->a = NULL;
	stacks->b = NULL;

	// Test 12
	printf(YELLOW "\n--- TEST 12: Unit Test Push (pa/pb)  ---\n" RESET);
	int vals_a1[] = {10};
	int vals_b1[] = {20};

	stacks->a = create_test_stack(vals_a1, 1);
	stacks->b = create_test_stack(vals_b1, 1);
	
	printf("Initial State:\n");
	print_stack("A", stacks->a);
	print_stack("B", stacks->b);

	// Test pb: A -> B
	printf("\nAction: pb\n");
	pb(stacks);
	print_stack("A", stacks->a);
	print_stack("B", stacks->b);
	assert_test(ft_lstsize(stacks->a) == 0 && ft_lstsize(stacks->b) == 2, "Push B test");

	// Test pa: B -> A
	printf("\nAction: pa\n");
	pa(stacks);
	print_stack("A", stacks->a);
	print_stack("B", stacks->b);
	assert_test(ft_lstsize(stacks->a) == 1 && ft_lstsize(stacks->b) == 1, "Push A test");

	// Test Edge case: pa on empty stack
	printf("\nAction: pa on empty B stack (Should do nothing)\n");
	pa(stacks);
	pa(stacks);
	print_stack("A", stacks->a);
	print_stack("B", stacks->b);
	assert_test(ft_lstsize(stacks->a) == 2 && ft_lstsize(stacks->b) == 0, "Push A on empty stac test");

	clear_stacks(stacks);

	// Test 13
	printf(YELLOW "\n--- TEST 13: Unit Test Swap (sa/sb/ss)  ---\n" RESET);
	int vals_a[] = {10, 20, 30};
	int vals_b[] = {40, 50 ,60};

	stacks->a = create_test_stack(vals_a, 3);
	stacks->b = create_test_stack(vals_b, 3);
	
	printf("Initial State:\n");
	print_stack("A", stacks->a);
	print_stack("B", stacks->b);

	// Test sa: A[0] <-> A[1]
	printf("\nAction: sa\n");
	sa(stacks);
	print_stack("A", stacks->a);
	assert_test(ft_lstsize(stacks->a) == 3 && ((t_node_content *)stacks->a->content)->rank == 1, "Swap A");

	// Test sa: B[0] <-> B[1]
	printf("\nAction: sb\n");
	sb(stacks);
	print_stack("B", stacks->b);
	assert_test(ft_lstsize(stacks->b) == 3 && ((t_node_content *)stacks->b->content)->rank == 1, "Swap B");

	// Test ss: AB[1] <-> AB[0]
	printf("\nAction: ss\n");
	ss(stacks);
	print_stack("A", stacks->a);
	print_stack("B", stacks->b);
	assert_test(ft_lstsize(stacks->a) == 3 && ft_lstsize(stacks->b) == 3 && ((t_node_content *)stacks->a->content)->rank == 0 && ((t_node_content *)stacks->b->content)->rank == 0, "Swap Both");
	
	clear_stacks(stacks);

	// Test 14
	// Test on sa on Emtpy Stack
	printf(YELLOW "\n--- TEST 14: Edge Cases Swap(sa/sb)  ---\n" RESET);
	printf("Initial State:\n");
	print_stack("A", stacks->a);
	printf("\nAction: sa on EMPTY stack\n");
	sa(stacks);
	print_stack("A", stacks->a);
	assert_test(stacks->a == NULL, "sa on empty stack");

	// Test on sa on Stack size 1
	stacks->a = create_test_stack(vals_a1, 1);
	printf("\nAction: sa on SIZE 1 stack (Rank 0)\n");
	sa(stacks);
	print_stack("A", stacks->a);
	assert_test(ft_lstsize(stacks->a) == 1 && ((t_node_content *)stacks->a->content)->rank == 0, "sa on SIZE 1 stack");
	
	// Test on sb on Emtpy Stack
	printf("Initial State:\n");
	print_stack("B", stacks->b);
	printf("\nAction: sb on EMPTY stack\n");
	sb(stacks);
	print_stack("B", stacks->b);
	assert_test(stacks->b == NULL, "sb on empty stack");

	// Test on sb on Stack size 1
	stacks->b = create_test_stack(vals_b1, 1);
	printf("\nAction: sb on SIZE 1 stack (Rank 0)\n");
	sb(stacks);
	print_stack("B", stacks->b);
	assert_test(ft_lstsize(stacks->b) == 1 && ((t_node_content *)stacks->b->content)->rank == 0, "sb on SIZE 1 stack");

	clear_stacks(stacks);

	// Test 15
	printf(YELLOW "\n--- TEST 15: Unit Test rotate (ra/rb/rr)  ---\n" RESET);
	stacks->a = create_test_stack(vals_a, 3);
	stacks->b = create_test_stack(vals_b, 3);

	printf("Initial State:\n");
	print_stack("A", stacks->a);
	print_stack("B", stacks->b);

	// Test ra
	printf("\nAction: ra\n");
	ra(stacks);
	print_stack("A", stacks->a);
	assert_test(ft_lstsize(stacks->a) == 3 && ((t_node_content *)stacks->a->content)->rank == 1, "Rotate A");

	// Test rb
	printf("\nAction: rb\n");
	rb(stacks);
	print_stack("B", stacks->b);
	assert_test(ft_lstsize(stacks->b) == 3 && ((t_node_content *)stacks->b->content)->rank == 1, "Rotate B");

	// Test rr
	printf("\nAction: rr\n");
	rr(stacks);
	print_stack("A", stacks->a);
	print_stack("B", stacks->b);
	assert_test(ft_lstsize(stacks->a) == 3 && ft_lstsize(stacks->b) == 3 && ((t_node_content *)stacks->a->content)->rank == 2 && ((t_node_content *)stacks->b->content)->rank == 2, "Rotate Both");

	clear_stacks(stacks);

	//Test 16
	printf(YELLOW "\n--- TEST 16: Unit Test reverse rotate (rra/rrb)  ---\n" RESET);
	stacks->a = create_test_stack(vals_a, 3);
	stacks->b = create_test_stack(vals_b, 3);
	
	printf("Initial State:\n");
	print_stack("A", stacks->a);
	print_stack("B", stacks->b);

	// Test rra
	printf("\nAction: rra\n");
	rra(stacks);
	print_stack("A", stacks->a);
	assert_test(ft_lstsize(stacks->a) == 3 && ((t_node_content *)stacks->a->content)->rank == 2, "Reverse Rotate A");

	// Test rrb
	printf("\nAction: rrb\n");
	rrb(stacks);
	print_stack("B", stacks->b);
	assert_test(ft_lstsize(stacks->b) == 3 && ((t_node_content *)stacks->b->content)->rank == 2, "Reverse Rotate B");

	// Test rrr
	printf("\nAction: rrr\n");
	rrr(stacks);
	print_stack("A", stacks->a);
	print_stack("B", stacks->b);
	assert_test(ft_lstsize(stacks->a) == 3 && ft_lstsize(stacks->b) == 3 && ((t_node_content *)stacks->a->content)->rank == 1 && ((t_node_content *)stacks->b->content)->rank == 1, "Reverse Rotate Both");

	//Test 17
	printf(YELLOW "\n--- TEST 17: Unit Test Tinny Sort (All Permutations)  ---\n" RESET);
	//Case 0: 0 1 2
	printf(YELLOW "\nCase: 0 1 2\n" RESET);
	int p1[] = {10, 20, 30};
	stacks->a =create_test_stack(p1, 3);
	print_stack("A", stacks->a);
	ft_tiny_sort(stacks);
	print_stack("A", stacks->a);
	assert_test(ft_is_sorted_stack(stacks->a), "Tiny Sort Case 0 1 2");
	clear_stacks(stacks);

	//Case: 0 2 1
	printf(YELLOW "\nCase: 0 2 1\n" RESET);
	int p2[] = {10, 30, 20};
	stacks->a =create_test_stack(p2, 3);
	print_stack("A", stacks->a);
	ft_tiny_sort(stacks);
	print_stack("A", stacks->a);
	assert_test(ft_is_sorted_stack(stacks->a), "Tiny Sort Case 0 2 1");
	clear_stacks(stacks);
	
	//Case: 1 0 2
	printf(YELLOW "\nCase: 1 0 2\n" RESET);
	int p3[] = {20, 10, 30};
	stacks->a =create_test_stack(p3, 3);
	print_stack("A", stacks->a);
	ft_tiny_sort(stacks);
	print_stack("A", stacks->a);
	assert_test(ft_is_sorted_stack(stacks->a), "Tiny Sort Case 1 0 2");
	clear_stacks(stacks);
	
	//Case: 1 2 0
	printf(YELLOW "\nCase: 1 2 0\n" RESET);
	int p4[] = {20, 30, 10};
	stacks->a =create_test_stack(p4, 3);
	print_stack("A", stacks->a);
	ft_tiny_sort(stacks);
	print_stack("A", stacks->a);
	assert_test(ft_is_sorted_stack(stacks->a), "Tiny Sort Case 1 2 0");
	clear_stacks(stacks);
	
	//Case: 2 0 1
	printf(YELLOW "\nCase: 2 0 1\n" RESET);
	int p5[] = {30, 10, 20};
	stacks->a =create_test_stack(p5, 3);
	print_stack("A", stacks->a);
	ft_tiny_sort(stacks);
	print_stack("A", stacks->a);
	assert_test(ft_is_sorted_stack(stacks->a), "Tiny Sort Case 2 0 1");
	clear_stacks(stacks);
	
	//Case: 2 1 0
	printf(YELLOW "\nCase: 2 1 0\n" RESET);
	int p6[] = {30, 10, 20};
	stacks->a =create_test_stack(p6, 3);
	print_stack("A", stacks->a);
	ft_tiny_sort(stacks);
	print_stack("A", stacks->a);
	assert_test(ft_is_sorted_stack(stacks->a), "Tiny Sort Case 2 1 0");
	clear_stacks(stacks);

	//Test 18
	printf(YELLOW "\n--- TEST 18: Unit Test Small Sort (4 - 5 elements)  ---\n" RESET);
	// Case: 4 elements random order
	printf(YELLOW "\nCase: 4 unsorted elements\n" RESET);
	int ss1[] = {40, 10, 30, 20};
	stacks->a = create_test_stack(ss1, 4);
	print_stack("A", stacks->a);
	ft_small_sort(stacks);
	assert_test(ft_is_sorted_stack(stacks->a) && ft_lstsize(stacks->b) == 0, "Small Sort: 4 elements");
	clear_stacks(stacks);

	// Case: 5 elements random order
	printf(YELLOW "\nCase: 5 unsorted elements\n" RESET);
	int ss2[] = {40, 10, 30, 50, 20};
	stacks->a = create_test_stack(ss2, 5);
	print_stack("A", stacks->a);
	ft_small_sort(stacks);
	assert_test(ft_is_sorted_stack(stacks->a) && ft_lstsize(stacks->b) == 0, "Small Sort: 4 elements");
	clear_stacks(stacks);
	return (0);
}
