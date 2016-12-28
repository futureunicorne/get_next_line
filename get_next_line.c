/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:38:37 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/12/28 17:32:31 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_retour(char *map)
{
	static int	mem;
	char		*dst;
	int			i;
	t_pos		pos;

	i = 0;
	ft_memset(&pos, 0, sizeof(t_pos));
	while (map[i])
	{
		if (map[i] == '\n' && mem == pos.flag)
		{
			dst = ft_strsub((const char*)map, pos.start, i - pos.start);
			mem++;
			return (dst);
		}
		if (map[i] == '\n')
		{
			pos.flag++;
			pos.start = i + 1;
		}
		i++;
	}
	return (NULL);
}

int		get_next_line(int fd, char **line)
{
	int				ret;
	char			*map;
	char			*dst1;
	char			buf[BUFF_SIZE + 1];

	map = "";
	ret = 0;
	if (fd == - 1)
		return (0);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		map = ft_strjoin(map, buf);
		dst1 = check_retour(map);
		if (dst1 != NULL)
		{
			*line = dst1;
			return (1);
		}
	}
	return (0);
}
