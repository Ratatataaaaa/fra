/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:52:59 by cwing             #+#    #+#             */
/*   Updated: 2020/11/06 13:09:41 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;

	i = 0;
	if (n == 0 || (n + 1 < n))
		return (NULL);
	while (n != 0)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)&(s)[i]);
		n--;
		i++;
	}
	return (NULL);
}
