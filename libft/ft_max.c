/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:25:31 by wanton            #+#    #+#             */
/*   Updated: 2019/09/17 11:49:22 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_max(int *nb, size_t size)
{
	size_t	i;
	int		res;

	res = 0;
	if (nb)
	{
		i = 0;
		while (i < size)
		{
			if (res < nb[i])
				res = nb[i];
			i++;
		}
	}
	return (res);
}