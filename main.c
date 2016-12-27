/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 09:20:27 by hel-hadi          #+#    #+#             */
/*   Updated: 2016/12/27 09:21:52 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/get_next_line.h"

int	main_get_next_line(int argc, char **argv)
{
	if (argc != 2)
		get_next_line(1, argv);
	else
	{
		ft_putendl("usage: please select only one file");
		ft_putstr("hamza");
	}
}
