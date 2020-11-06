/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 01:53:27 by cwing             #+#    #+#             */
/*   Updated: 2020/11/06 13:09:41 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push_back(t_list **alst,
		void const *content, size_t content_size)
{
	if (alst)
	{
		while (*alst)
			alst = &((*alst)->next);
		*alst = ft_lstnew(content, content_size);
	}
}
