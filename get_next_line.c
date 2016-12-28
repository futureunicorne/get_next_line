/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:38:37 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/12/28 11:46:16 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/get_next_line.h"
// check les variables static
// check les defines
// heck les fd et appel read
// check les leaks

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	i;
	int		j;

	i = (size_t)start;
	j = 0;
	if ((s1 = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	if (s)
	{
		len = len + i;
		while (i < len)
		{
			s1[j] = s[i];
			i++;
			j++;
		}
		s1[j] = '\0';
	}
	return (s1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s3;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if ((s3 = malloc(sizeof(s1) * ft_strlen(s1) + ft_strlen(s2) + 1)) == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}
void	*ft_memset(void *s, int c, size_t n)
{
	char	*s1;
	size_t	i;

	i = 0;
	if (c >= 0 || c <= 127)
	{
		s1 = (char*)s;
		while (i < n)
		{
			s1[i] = c;
			i++;
		}
	}
	return (s);
}

char *ft_clean_backslash(char *map)
{
	int i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			map[i] = '\0';
			return (map);
		}
		i++;
	}
	return (map);
}

int		check_retour(char *map)
{
	static int	mem;
	char 		*dst;
	int			i;
	t_pos		pos;

	i = 0;
	ft_memset(&pos, 0, sizeof(t_pos));
	while (map[i])
	{
		if (map[i] == '\n' && mem == pos.flag)
		{
			dst = ft_strsub((const char*)map, pos.start, i - pos.start);
			//dst = ft_clean_backslash(dst);
			printf("%s",dst);
			mem++;
			free(map);
			return (1);
		}
		if (map[i] == '\n')
		{
			pos.flag++;
			pos.start = i;
		}
		i++;
	}
	return (0);
}

int	get_next_line(int fd, char *line)
{
	int				ret;
	char 			*map;
	char 			buf[BUFF_SIZE + 1];

	map = "";
	ret = 0;
	if ((fd = open(line, O_RDONLY)) == -1)
		return (1);

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret]= '\0';
		map = ft_strjoin(map, buf);
		if (check_retour(map) == 1)
			return (0);
	}
	if (close(fd) == -1)
		return (0);
	else if (close(fd) == 0)
		printf("end_file");
	return (0);
}
