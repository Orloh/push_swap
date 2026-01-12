/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:58:05 by orhernan          #+#    #+#             */
/*   Updated: 2026/01/12 18:34:02 by orhernan         ###   ########.fr       */
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

int	main(void)
{
	t_int_arr	res;
	int	i;

	// Test 1
	printf(YELLOW "--- TEST 1: Multiple Args (1 42 -5) ---\n" RESET);
	char	*test1[] = {"push_swap", "1", "42", "-5", NULL};
	res = ft_parse_args(4, test1);
	print_arr(res);
	if (res.data != NULL && res.size == 3)
		printf(GREEN "[PASS] Array created correctly.\n" RESET);
	else
		printf(RED "[FAIL] Array creation failed.\n" RESET);
	ft_free_int_arr(&res);

	// Test2
	printf(YELLOW "\n--- TEST 2: Quoted String (\"100 200 300 1000\") ---\n" RESET);
	char	*test2[] = {"push_swap", "100 200 300 1000", NULL};
	res = ft_parse_args(2, test2);
	print_arr(res);
	if (res.data != NULL && res.size == 4)
		printf(GREEN "[PASS] Split args parsed correctly.\n" RESET);
	else
		printf(RED "[FAIL] Split args parsing failed.\n" RESET);
	ft_free_int_arr(&res);
	
	// Test 3
	printf(YELLOW "\n--- TEST 3: Overflow (Should be NULL) ---\n" RESET);
	char	*test3[] = {"push_swap", "2147483648", NULL};
	res = ft_parse_args(2, test3);
	print_arr(res);
	if (res.data == NULL)
		printf(GREEN "[PASS] Overflow detected succesfully (NULL).\n" RESET);
	else
		printf(RED "[FAIL] Overflow NOT detected (Retrned pointer).\n" RESET);
	ft_free_int_arr(&res);

	// Test 4
	printf(YELLOW "\n--- TEST 4: Alpha chars (Should be NULL) ---\n" RESET);
	char	*test4[] = {"push_swap", "12", "34a", "56", NULL};
	res = ft_parse_args(4, test4);
	print_arr(res);
	if (res.data == NULL) 
		printf(GREEN "[PASS] Invalid input detected successfully (NULL).\n" RESET);
	else
		printf(RED "[FAIL] Invalid input NOT detected.\n" RESET);
	ft_free_int_arr(&res);

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
	if (ft_is_sorted(&res)) 
		printf(GREEN "[PASS] Array is sorted.\n" RESET);
	else
		printf(RED "[FAIL] Array is NOT sorted.\n" RESET);
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
	if (ft_is_sorted(&res)) 
		printf(GREEN "[PASS] Array is sorted.\n" RESET);
	else
		printf(RED "[FAIL] Array is NOT sorted.\n" RESET);
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
	if (ft_is_sorted(&res)) 
		printf(GREEN "[PASS] Array is sorted.\n" RESET);
	else
		printf(RED "[FAIL] Array is NOT sorted.\n" RESET);
	ft_free_int_arr(&res);

	// Test 8
	printf(YELLOW "\n--- TEST 8: Stack Init (Scrambled: 42 1 -5 10) ---\n" RESET);
	char	*test8[] = {"push_swap", "42", "1", "-5", "10", NULL};
	res = ft_parse_args(5, test8);
	t_list	*stack_a = ft_init_stack(&res);
	print_stack("A", stack_a);
	if (stack_a != NULL && ft_lstsize(stack_a) == 4) 
		printf(GREEN "[PASS] Stack A initialized.\n" RESET);
	else
		printf(RED "[FAIL] Stack A initializaion error.\n" RESET);
	ft_lstclear(&stack_a, free);
	ft_free_int_arr(&res);

	// Test 9
	printf(YELLOW "\n--- TEST 9: Stack Init (Duplicates/Negative Mix) ---\n" RESET);
	char	*test9[] = {"push_swap", "100", "-100", "0", "50", NULL};
	res = ft_parse_args(5, test9);
	stack_a = ft_init_stack(&res);
	print_stack("A", stack_a);
	if (stack_a != NULL && ft_lstsize(stack_a) == 4) 
		printf(GREEN "[PASS] Stack A initialized with negatives.\n" RESET);
	else
		printf(RED "[FAIL] Stack A initializaion error.\n" RESET);
	ft_lstclear(&stack_a, free);
	ft_free_int_arr(&res);

	// Test 10
	printf(YELLOW "\n--- TEST 10: Stack Init (Single Element) ---\n" RESET);
	char	*test10[] = {"push_swap", "42", NULL};
	res = ft_parse_args(2, test10);
	stack_a = ft_init_stack(&res);
	print_stack("A", stack_a);
	if (stack_a != NULL && ft_lstsize(stack_a) == 1) 
		printf(GREEN "[PASS] Single element stack initialized.\n" RESET);
	else
		printf(RED "[FAIL] Single element stack initializaion error.\n" RESET);
	ft_lstclear(&stack_a, free);
	ft_free_int_arr(&res);

	// Test 11
	printf(YELLOW "\n--- TEST 11: Stack Init (Duplicates) 1 5 2 5 ---\n" RESET);
	char	*test11[] = {"push_swap", "1", "5", "2", "5", NULL};
	res = ft_parse_args(5, test11);
	stack_a = ft_init_stack(&res);
	print_stack("A", stack_a);
	if (stack_a == NULL)
	{
		printf(GREEN "[PASS] NULL (Duplicates detected succesfully)\n" RESET);
	}
	else
	{
		printf(RED "[FAIL] Stack initialized despite duplicates!\n" RESET);
		ft_lstclear(&stack_a, free);
	}
	ft_free_int_arr(&res);

	printf(YELLOW "\n--- OPERATION TESTING ---\n" RESET);	
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
	ft_lstadd_back(&(stacks->a), ft_lstnew(ft_new_content(10, 0)));
	ft_lstadd_back(&(stacks->b), ft_lstnew(ft_new_content(20, 1)));
	
	printf("Initial State:\n");
	print_stack("A", stacks->a);
	print_stack("B", stacks->b);

	// Test pb: A -> B
	printf("\nAction: pb\n");
	pb(stacks);
	print_stack("A", stacks->a);
	print_stack("B", stacks->b);
	if (ft_lstsize(stacks->a) == 0 && ft_lstsize(stacks->b) == 2)
		printf(GREEN "[PASS] pb executed correctly.\n" RESET);
	else
		printf(RED "[FAIL] pb execution failed (Stack size mismatch).\n" RESET);

	// Test pa: B -> A
	printf("\nAction: pa\n");
	pa(stacks);
	print_stack("A", stacks->a);
	print_stack("B", stacks->b);
	if (ft_lstsize(stacks->a) == 1 && ft_lstsize(stacks->b) == 1)
		printf(GREEN "[PASS] pa executed correctly.\n" RESET);
	else
		printf(RED "[FAIL] pa execution failed (Stack size mismatch).\n" RESET);

	// Test Edge case: pa on empty stack
	printf("\nAction: pa on empty B stack (Should do nothing)\n");
	pa(stacks);
	pa(stacks);
	print_stack("A", stacks->a);
	print_stack("B", stacks->b);
	if (ft_lstsize(stacks->a) == 2 && ft_lstsize(stacks->b) == 0)
		printf(GREEN "[PASS] pa on empty stack ignored correctly.\n" RESET);
	else
		printf(RED "[FAIL] pa modified an empty stack.\n" RESET);

	ft_lstclear(&(stacks->a), free);
	ft_lstclear(&(stacks->b), free);

	// Test 13
	printf(YELLOW "\n--- TEST 13: Unit Test Swap (sa/sb/ss)  ---\n" RESET);
	ft_lstadd_back(&(stacks->a), ft_lstnew(ft_new_content(10, 0)));
	ft_lstadd_back(&(stacks->a), ft_lstnew(ft_new_content(20, 1)));
	ft_lstadd_back(&(stacks->a), ft_lstnew(ft_new_content(30, 2)));
	
	ft_lstadd_back(&(stacks->b), ft_lstnew(ft_new_content(40, 0)));
	ft_lstadd_back(&(stacks->b), ft_lstnew(ft_new_content(50, 1)));
	ft_lstadd_back(&(stacks->b), ft_lstnew(ft_new_content(60, 2)));
	
	printf("Initial State:\n");
	print_stack("A", stacks->a);
	print_stack("B", stacks->b);

	// Test sa: A[0] <-> A[1]
	printf("\nAction: sa\n");
	sa(stacks);
	print_stack("A", stacks->a);
	if (ft_lstsize(stacks->a) == 3 && ((t_node_content *)stacks->a->content)->rank == 1)
		printf(GREEN "[PASS] sa executed correctly.\n" RESET);
	else
		printf(RED "[FAIL] sa execution failed (Stack didn't change).\n" RESET);

	// Test sa: B[0] <-> B[1]
	printf("\nAction: sb\n");
	sb(stacks);
	print_stack("B", stacks->b);
	if (ft_lstsize(stacks->b) == 3 && ((t_node_content *)stacks->b->content)->rank == 1)
		printf(GREEN "[PASS] sb executed correctly.\n" RESET);
	else
		printf(RED "[FAIL] sb execution failed (Stack didn't change).\n" RESET);

	// Test ss: AB[1] <-> AB[0]
	printf("\nAction: ss\n");
	ss(stacks);
	print_stack("A", stacks->a);
	print_stack("B", stacks->b);
	if (ft_lstsize(stacks->b) == 3 && ((t_node_content *)stacks->b->content)->rank == 0)
		printf(GREEN "[PASS] ss executed correctly.\n" RESET);
	else
		printf(RED "[FAIL] ss execution failed (Stack didn't change).\n" RESET);
	
	ft_lstclear(&(stacks->a), free);
	ft_lstclear(&(stacks->b), free);

	// Test 14
	
	// Test on sa on Emtpy Stack
	printf(YELLOW "\n--- TEST 14: Edge Cases Swap(sa/sb)  ---\n" RESET);
	ft_lstclear(&(stacks->a), free);
	printf("Initial State:\n");
	print_stack("A", stacks->a);
	printf("\nAction: sa on EMPTY stack\n");
	sa(stacks);
	if (stacks->a == NULL)
		printf(GREEN "[PASS] sa on empty stack handled safely.\n" RESET);
	else
		printf(RED "[FAIL] sa changed empty stack (pointer not NULL).\n" RESET);

	// Test on sa on Stack size 1
	ft_lstadd_back(&(stacks->a), ft_lstnew(ft_new_content(10, 0)));
	printf("\nAction: sa on SIZE 1 stack (Rank 0)\n");
	sa(stacks);
	if (ft_lstsize(stacks->a) == 1 && ((t_node_content *)stacks->a->content)->rank == 0)
		printf(GREEN "[PASS] sa on size 1 stack handled safely.\n" RESET);
	else
		printf(RED "[FAIL] sa modified stack of size 1.\n" RESET);
	
	// Test on sb on Emtpy Stack
	ft_lstclear(&(stacks->b), free);
	printf("Initial State:\n");
	print_stack("B", stacks->b);
	printf("\nAction: sb on EMPTY stack\n");
	sb(stacks);
	if (stacks->b == NULL)
		printf(GREEN "[PASS] sb on empty stack handled safely.\n" RESET);
	else
		printf(RED "[FAIL] sb changed empty stack (pointer not NULL).\n" RESET);

	// Test on sb on Stack size 1
	ft_lstadd_back(&(stacks->b), ft_lstnew(ft_new_content(20, 0)));
	printf("\nAction: sb on SIZE 1 stack (Rank 0)\n");
	sb(stacks);
	if (ft_lstsize(stacks->b) == 1 && ((t_node_content *)stacks->b->content)->rank == 0)
		printf(GREEN "[PASS] sb on size 1 stack handled safely.\n" RESET);
	else
		printf(RED "[FAIL] sb modified stack of size 1.\n" RESET);
	
	ft_lstclear(&(stacks->a), free);
	ft_lstclear(&(stacks->b), free);

	// Test 14
	printf(YELLOW "\n--- TEST 15: Unit Test rotate (ra/rb)  ---\n" RESET);
	ft_lstadd_back(&(stacks->a), ft_lstnew(ft_new_content(10, 0)));
	ft_lstadd_back(&(stacks->a), ft_lstnew(ft_new_content(20, 1)));
	ft_lstadd_back(&(stacks->a), ft_lstnew(ft_new_content(30, 2)));
	
	ft_lstadd_back(&(stacks->b), ft_lstnew(ft_new_content(40, 0)));
	ft_lstadd_back(&(stacks->b), ft_lstnew(ft_new_content(50, 1)));
	ft_lstadd_back(&(stacks->b), ft_lstnew(ft_new_content(60, 2)));
	
	printf("Initial State:\n");
	print_stack("A", stacks->a);
	print_stack("B", stacks->b);

	// Test ra
	printf("\nAction: ra\n");
	ra(stacks);
	print_stack("A", stacks->a);
	if (ft_lstsize(stacks->a) == 3 && ((t_node_content *)stacks->a->content)->rank == 1)
		printf(GREEN "[PASS] ra executed correctly.\n" RESET);
	else
		printf(RED "[FAIL] ra execution failed (Stack didn't change).\n" RESET);

	// Test rb
	printf("\nAction: rb\n");
	rb(stacks);
	print_stack("B", stacks->b);
	if (ft_lstsize(stacks->b) == 3 && ((t_node_content *)stacks->b->content)->rank == 1)
		printf(GREEN "[PASS] rb executed correctly.\n" RESET);
	else
		printf(RED "[FAIL] rb execution failed (Stack didn't change).\n" RESET);

	ft_lstclear(&(stacks->a), free);
	ft_lstclear(&(stacks->b), free);
	
	printf(YELLOW "\n--- TEST 16: Unit Test reverse rotate (rra/rrb)  ---\n" RESET);
	ft_lstadd_back(&(stacks->a), ft_lstnew(ft_new_content(10, 0)));
	ft_lstadd_back(&(stacks->a), ft_lstnew(ft_new_content(20, 1)));
	ft_lstadd_back(&(stacks->a), ft_lstnew(ft_new_content(30, 2)));
	
	ft_lstadd_back(&(stacks->b), ft_lstnew(ft_new_content(40, 0)));
	ft_lstadd_back(&(stacks->b), ft_lstnew(ft_new_content(50, 1)));
	ft_lstadd_back(&(stacks->b), ft_lstnew(ft_new_content(60, 2)));
	
	printf("Initial State:\n");
	print_stack("A", stacks->a);
	print_stack("B", stacks->b);

	// Test ra
	printf("\nAction: rra\n");
	rra(stacks);
	print_stack("A", stacks->a);
	if (ft_lstsize(stacks->a) == 3 && ((t_node_content *)stacks->a->content)->rank == 2)
		printf(GREEN "[PASS] rra executed correctly.\n" RESET);
	else
		printf(RED "[FAIL] sa execution failed (Stack didn't change).\n" RESET);

	// Test rb
	printf("\nAction: rrb\n");
	rrb(stacks);
	print_stack("B", stacks->b);
	if (ft_lstsize(stacks->b) == 3 && ((t_node_content *)stacks->b->content)->rank == 2)
		printf(GREEN "[PASS] rrb executed correctly.\n" RESET);
	else
		printf(RED "[FAIL] sb execution failed (Stack didn't change).\n" RESET);

	ft_lstclear(&(stacks->a), free);
	ft_lstclear(&(stacks->b), free);
	return (0);
}
