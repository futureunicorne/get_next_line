/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 09:20:27 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/03 17:46:08 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd_1;
	char	*line1;

	line1 = "";
	fd_1 = open(argv[1],O_RDONLY);
	if (argc == 2)
	{	/*
		while (get_next_line(fd_1, &line1))
		{
			printf("%s\n", line1);
		}*/
		get_next_line(fd_1, &line1);
		get_next_line(fd_1, &line1);
		get_next_line(fd_1, &line1);
		printf("%s\n",line1 );

	}
	if(close(fd_1) == -1)
		printf("Error Close	()");
	return (0);
}
