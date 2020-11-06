/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:01:24 by cwing             #+#    #+#             */
/*   Updated: 2020/11/06 13:09:41 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	size_t	n;

	n = 0;
	while ((s1[n] != '\0') && (s2[n] != '\0') && (s1[n] == s2[n]))
	{
		n++;
	}
	if ((s1[n] == '\0') && (s2[n] == '\0'))
		return (0);
	else if ((s1[n] == '\0') && (s2[n] != '\0'))
		return (-1);
	else if ((s1[n] != '\0') && (s2[n] == '\0'))
		return (1);
	else
		return (s1[n] - s2[n]);
}