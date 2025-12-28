/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:58:05 by orhernan          #+#    #+#             */
/*   Updated: 2025/12/28 22:44:02 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <time.h>

void	 print_arr(int *arr, int size)
{
	int i = 0;
	if (!arr)
	{
		printf("Result: NULL (Error detected succesfully)\n");
		return ;
	}
	printf("arr: ");
	while (i < size)
	{
		printf("[%d] ", arr[i]);
		i++;
	}
	printf("\nSize: %d\n", size);
}

int	main(void)
{
	int	*res;
	int	size;
	int	i;

	// Test 1
	printf("--- TEST 1: Multiple Args (1 42 -5) ---\n");
	char	*test1[] = {"push_swap", "1", "42", "-5", NULL};
	res = ft_parse_args(4, test1, &size);
	print_arr(res, size);
	free(res);

	// Test2
	printf("\n--- TEST 2: Quoted String (\"100 200 300 1000\") ---\n");
	char	*test2[] = {"push_swap", "100 200 300 1000", NULL};
	res = ft_parse_args(2, test2, &size);
	print_arr(res, size);
	free(res);
	
	// Test 3
	printf("\n--- TEST 3: Overflow (Should be NULL) ---\n");
	char	*test3[] = {"push_swap", "2147483648", NULL};
	res = ft_parse_args(2, test3, &size);
	print_arr(res, size);
	free(res);

	// Test 4
	printf("\n--- TEST 4: Alpha chars (Should be NULL) ---\n");
	char	*test4[] = {"push_swap", "12", "34a", "56", NULL};
	res = ft_parse_args(2, test4, &size);
	print_arr(res, size);
	free(res);

	// Test 5
	printf("\n--- TEST 5: Random Sort (500 integers) ---\n");	
	size = 500;
	res = (int *)ft_calloc(size, sizeof(int));
	i = 0;
	if (!res)
		return (1);
	srand(time(NULL));
	while (i < size)
	{
		res[i] = ((rand() << 16 | rand()));
		i++;
	}
	printf("First 5 unsorted: %d %d %d %d %d\n", res[0], res[1], res[2], res[3], res[4]);
	ft_sort_array(res, size);
	printf("First 5 sorted: %d %d %d %d %d\n", res[0], res[1], res[2], res[3], res[4]);
	free(res);

	// Test 6
	printf("\n--- TEST 5: Random Sort (500 integers) ---\n");	
	int test6[] = {1, 2, 3, 4,5};
	ft_sort_array(test6, 5);
	print_arr(test6, 5);

	// Test 7
	printf("\n--- TEST 5: Random Sort (500 integers) ---\n");	
	int test7[] = {5, 4, 3, 2, 1};
	ft_sort_array(test7, 5);
	print_arr(test7, 5);
	return (0);
}
