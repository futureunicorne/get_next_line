/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 09:20:27 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/12/28 18:26:25 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*line1;

	line1 = "";
	i = 0;
	if (argc == 2)
	{
		while (i < 5)
		{
			fd = open(argv[1], O_RDONLY);
			get_next_line(fd, &line1);
			printf("%s\n", line1);
			i++;
		}
	}
	else
		printf("usage: please select one file");
	return (0);
}
