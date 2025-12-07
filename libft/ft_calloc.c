/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:14:11 by orhernan          #+#    #+#             */
/*   Updated: 2025/10/16 22:24:34 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;
	size_t		total;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (count > 0 && size > SIZE_MAX / count)
		return (NULL);
	total = count * size;
	tmp = malloc (total);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, total);
	return (tmp);
}
