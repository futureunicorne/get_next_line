/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 09:20:27 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/12/28 10:10:16 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/get_next_line.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		get_next_line(1, argv[1]);
		get_next_line(1, argv[1]);

	}
	else
		printf("usage: please select one file");
	return (0);
}
