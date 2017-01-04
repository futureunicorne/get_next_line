/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 09:20:27 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/04 16:14:05 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd_1;
	int		fd_2;
	char	*line1;
	char	*line2;

	line1 = "";
	line2 = "";
	fd_1 = open(argv[1],O_RDONLY);
	fd_2 = open(argv[2],O_RDONLY);
	if (argc == 3)
	{/*
		while (get_next_line(fd_1, &line1))
		{
			printf("%s\n", line1);
		}*/
		get_next_line(fd_1, &line1);
		printf("%s\n", line1);
		get_next_line(fd_2, &line2);
		printf("%s\n", line2);
		get_next_line(fd_1, &line1);
		printf("%s\n", line1);

	}
	if(close(fd_1) == -1)
		printf("Error Close	()");
	return (0);
}
