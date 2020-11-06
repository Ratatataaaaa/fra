/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:26:10 by cwing             #+#    #+#             */
/*   Updated: 2020/11/06 13:11:57 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE2_H
# define GET_NEXT_LINE2_H
# define BUFF_SIZE 4096

# include <unistd.h>
# include <stdlib.h>

int				get_next_line2(const int fd, char **line);
typedef struct	s_file_buf
{
	int		fd;
	char	*data;
}				t_file_buf;

#endif
