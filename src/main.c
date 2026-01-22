/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:56:36 by orhernan          #+#    #+#             */
/*   Updated: 2025/12/29 17:21:17 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", STDOUT_FILENO);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_int_arr	num_arr;

	if (argc < 2)
		return (0);
	stacks = malloc(sizeof(t_stacks));
	if (stacks == NULL)
		ft_error();
	stacks->a = NULL;
	stacks->b = NULL;
	num_arr = ft_parse_args(argc, argv);
	if (!num_arr.data)
		ft_error();
	ft_free_int_arr(&num_arr);
	return (0);
}
