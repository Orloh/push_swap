/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_dllstnew.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:52:59 by orhernan          #+#    #+#             */
/*   Updated: 2025/12/14 22:10:09 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "libft.h"

void	setUp(void){}

void	tearDown(void){}

void	test_dllstnew_valid_content(void)
{
	int		data;
	t_dllist	*node;

	// Creating node
	data = 42;
	node = ft_dllstnew(&data);

	// 1. Allocation check
	TEST_ASSERT_NOT_NULL_MESSAGE(node, "Node should not be NULL.");
	
	// 2. Content assignment check (pointer equality and value check)
	TEST_ASSERT_EQUAL_PTR_MESSAGE(&data, node->content, "Content pointer should match the input data pointer.");
	TEST_ASSERT_EQUAL_INT_MESSAGE(data, *(int *)node->content, "Content value should be 42.");
	
	// 3. Doubly linked list initialization check
	TEST_ASSERT_NULL_MESSAGE(node->next, "'next' pointer must be initialized to NULL.");
	TEST_ASSERT_NULL_MESSAGE(node->prev, "'prev' pointer must be initialized to NULL.");
	
	//Cleanup
	free(node);
}

void	test_dllstnew_null_content(void)
{
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_dllstnew_valid_content);
	RUN_TEST(test_dllstnew_null_content);
	return UNITY_END();
}
