/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 22:48:49 by cwing             #+#    #+#             */
/*   Updated: 2020/11/06 13:09:41 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	ft_bzero(str, size);
	return ((void *)str);
}
