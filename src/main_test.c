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

int	main(void)
{
	t_int_arr	res;
	int	i;

	// Test 1
	printf("--- TEST 1: Multiple Args (1 42 -5) ---\n");
	char	*test1[] = {"push_swap", "1", "42", "-5", NULL};
	res = ft_parse_args(4, test1);
	print_arr(res);
	ft_free_int_arr(res);

	// Test2
	printf("\n--- TEST 2: Quoted String (\"100 200 300 1000\") ---\n");
	char	*test2[] = {"push_swap", "100 200 300 1000", NULL};
	res = ft_parse_args(2, test2);
	print_arr(res);
	ft_free_int_arr(res);
	
	// Test 3
	printf("\n--- TEST 3: Overflow (Should be NULL) ---\n");
	char	*test3[] = {"push_swap", "2147483648", NULL};
	res = ft_parse_args(2, test3);
	print_arr(res);
	ft_free_int_arr(res);

	// Test 4
	printf("\n--- TEST 4: Alpha chars (Should be NULL) ---\n");
	char	*test4[] = {"push_swap", "12", "34a", "56", NULL};
	res = ft_parse_args(2, test4);
	print_arr(res);
	ft_free_int_arr(res);

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
	ft_sort_array(res);
	printf("First 5 sorted: %d %d %d %d %d\n", res.data[0], res.data[1], res.data[2], res.data[3], res.data[4]);
	ft_free_int_arr(res);

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
	ft_sort_array(res);
	print_arr(res);
	ft_free_int_arr(res);

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
	{
		i--;
		res.data[i] = i + 1;
	}
	ft_sort_array(res);
	print_arr(res);
	ft_free_int_arr(res);

	return (0);
}
