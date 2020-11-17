/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 21:10:37 by cclaude           #+#    #+#             */
/*   Updated: 2020/11/16 16:13:49 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		char	*line;
		int		fd = open(av[1], O_RDONLY);
		int		ret = 1;

		while (ret == 1)
		{
			ret = get_next_line(fd, &line);
			if (ret)
				printf("%s\n", line);
			else
				printf("%s", line);
		}
	}
	return (0);
}
