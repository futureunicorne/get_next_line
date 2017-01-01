/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 09:20:27 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/12/31 02:46:12 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line1;

	line1 = "";
	fd = open(argv[1], O_RDONLY);
	if (argc == 2)
	{
		while (get_next_line(fd, &line1))
		{
			printf("%s\n", line1);
		}/*
		get_next_line(fd, &line1);
		get_next_line(fd, &line1);
		printf("%s", line1);
		*/
	}
	else
		printf("usage: please select one file");
	return (0);
}
