/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:38:37 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/12/29 17:58:43 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_charcmp(char a, char b)
{
	if (a == '\n')
		return (1);
	if (a == b)
		return (1);
	return (0);
}

char	*check_ret_cmp(char *str, char *line)
{
	int		i;
	t_pos	pos;

	i = 0;
	ft_memset(&pos, 0, sizeof(t_pos));
	while (str[i])
	{
		if (ft_strstr(str, line) == 1)
		if (str[i] == '\n')
			pos.start = i + 1;
		i++;
	}
	i = pos.start;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			str = ft_strsub((const char*)str, pos.start, i - pos.start);
			return (str);
		}
		i++;
	}
	return (NULL);
}

int		get_next_line(int fd, char **line)
{
	int				ret;
	static char		*mem = "";
	char			*map;
	char			buf[BUFF_SIZE + 1];

	map = "";
	ret = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		mem = ft_strjoin(mem, buf);
	}
	map = check_ret_cmp(mem, *line);

	if (map != NULL)
	{
		*line = map;
		return (1);
	}
	return (0);
}
