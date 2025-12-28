/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:34:40 by orhernan          #+#    #+#             */
/*   Updated: 2025/12/28 22:44:06 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Helper function to check if string is a valid integer.
 * Handles integer overflows.
 */
static int	ft_is_valid_int(const char *str, long *val)
{
	long	res;
	int	i;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;

	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	if (!str[i])
		return (0);
	while(str[i])
	{
		if(!ft_isdigit(str[i]))
			return (0);
		res = res * 10 + (str[i++] - '0');
		if((sign * res) > INT_MAX || (sign * res) < INT_MIN)
			return (0);
	}
	*val = sign * res;
	return (1);
}

/*
 * Normalizes and validates command line args.
 * Handles both single strings ("1 2 3") and multiple args (1 2 3).
 * It checks for non-digits and integer overflows.
 * Returns a malloc'd int array or NULL if any validation fails.
 */
int	*ft_parse_args(int argc, char **argv, int *size)
{
	char	**tmp_args;
	long	val;
	int		*res;
	int		i;

	if (argc == 2)
		tmp_args = ft_split(argv[1], ' ');
	else
		tmp_args = argv + 1;
	if (!tmp_args || !tmp_args[0])
		return (NULL);
	*size = 0;
	while (tmp_args[*size])
		(*size)++;
	res = ft_calloc((*size), sizeof(int));
	if (!res)
	{
		if (argc == 2)
			ft_free_split(tmp_args);
		return (NULL);
	}
	i = -1;
	while (++i < *size)
	{
		if (!ft_is_valid_int(tmp_args[i], &val))
		{
			if (argc == 2)
				ft_free_split(tmp_args);
			return (free(res), NULL);
		}
		res[i] = (int)val;
	}
	if (argc == 2)
		ft_free_split(tmp_args);
	return (res);
}
