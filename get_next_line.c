/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:38:37 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/03 17:47:21 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		return (i);
	else
		return (-1);

}
int		get_next_line(int fd, char **line)
{
	static char		*mem = "";
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if (fd <= 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) && check(*line) == -1)
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		mem = ft_strjoin(mem, buf);
		*line = mem;
		printf("%s\n",mem );
	}
	if (check(*line) != -1)
	{
		*line = ft_strsub((const char*)*line, 0, check(*line) + 1);
		mem = ft_strchr(mem, '\n');
		return (1);
	}
	else if (check(*line) == -1 && ret == 0)
	{
		*line = ft_strsub((const char*)*line, 0, check(*line) + 1);
		return (1);
	}

	return (0);
}