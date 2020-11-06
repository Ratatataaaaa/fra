/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:21:10 by cwing             #+#    #+#             */
/*   Updated: 2020/11/06 13:09:41 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	if (alst)
	{
		if ((*alst)->next)
			ft_lstdel(&(*alst)->next, del);
		ft_lstdelone(alst, del);
	}
}
