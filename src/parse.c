/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:34:40 by orhernan          #+#    #+#             */
/*   Updated: 2025/12/29 17:21:20 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/*
 * Helper function to check if string is a valid integer.
 * Handles integer overflows.
 */
static int	ft_is_valid_int(const char *str, long *val)
{
	long	res;
	int		i;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		res = res * 10 + (str[i++] - '0');
		if ((sign * res) > INT_MAX || (sign * res) < INT_MIN)
			return (0);
	}
	*val = sign * res;
	return (1);
}

void	ft_free_int_arr(t_int_arr *int_arr)
{
	if (int_arr->data)
		free(int_arr->data);
	int_arr->data = NULL;
	int_arr->size = 0;
}

/*
 * Normalizes and validates command line args.
 * Handles both single strings ("1 2 3") and multiple args (1 2 3).
 * It checks for non-digits and integer overflows.
 * Returns a malloc'd int array or NULL if any validation fails.
 */
t_int_arr	ft_parse_args(int argc, char **argv)
{
	t_int_arr	int_arr;
	char		**tmp_args;
	long		val;
	int			i;

	int_arr.size = 0;
	tmp_args = argv + 1;
	if (argc == 2)
		tmp_args = ft_split(argv[1], ' ');
	while (tmp_args && tmp_args[int_arr.size])
		int_arr.size++;
	int_arr.data = ft_calloc((int_arr.size), sizeof(int));
	i = -1;
	while (int_arr.data && ++i < int_arr.size)
	{
		if (ft_is_valid_int(tmp_args[i], &val))
			int_arr.data[i] = (int)val;
		else
			ft_free_int_arr(&int_arr);
	}
	if (argc == 2 && tmp_args)
		ft_free_split(tmp_args);
	return (int_arr);
}
