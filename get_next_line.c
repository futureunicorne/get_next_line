/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:38:37 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/12/27 09:27:03 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/get_next_line.h"
// check les variables static
// check les defines
// heck les fd et appel read
// check les leaks 
int	get_next_line(const int fd, char **line)
{
	int		ret;
	char	buf[BUFF_SIZE];

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
	}
	if (close(fd) == -1)
		return (0);
	else if (close(fd) == 0)
		ft_putendl("end_file");
	return (0);
}
