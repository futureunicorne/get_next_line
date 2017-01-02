/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:38:37 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/02 18:43:19 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cut_text(char *str)
{
	int	i;

	i =	0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (str + i + 1);
		i++;
	}
	return (NULL);
}

char	*check_ret_cmp(char *str)
{
	int		i;
	char	*dst;
	t_pos	pos;

	i = 0;
	ft_memset(&pos, 0, sizeof(t_pos));
	while (str[i])
	{
		if (str[i] == '\n')
		{
			dst = ft_strsub((const char*)str, pos.start, i - pos.start);
			return (dst);
		}
		if (str[i + 1] == '\0' && str[i] != '\n')
		{
			dst = ft_strsub((const char*)str, pos.start, i - pos.start +1);
			return (dst);
		}
		i++;
	}
	return (NULL);
}

int		get_next_line(int fd, char **line)
{
	static char		*mem = "";
	char			*map;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	map = "";
	ret = 0;
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		mem = ft_strjoin(mem, buf);
	}
	if (mem == NULL)
		return (0);
	map = ft_strdup(check_ret_cmp(mem));
	mem = cut_text(mem);
	if (map != NULL)
	{
		*line = ft_strdup(map);
		return (1);
	}
	return (0);
}
