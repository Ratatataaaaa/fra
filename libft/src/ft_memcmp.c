/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 22:46:15 by cwing             #+#    #+#             */
/*   Updated: 2020/11/10 19:52:29 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char*)(s1);
	ss2 = (unsigned char*)(s2);
	i = 0;
	if (n == 0)
		return (0);
	while (n != 0)
	{
		if (ss1[i] < ss2[i])
			return (ss1[i] - ss2[i]);
		if (ss1[i] > ss2[i])
			return (ss1[i] - ss2[i]);
		if (ss1[i] == ss2[i])
		{
			++i;
			--n;
		}
	}
	return (0);
}
