/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:52:01 by cclaude           #+#    #+#             */
/*   Updated: 2020/11/17 21:21:35 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	join_buffer(char **line, char *buf, int i, int j)
{
	char	*new;// Pass i and j as parameters so I don't have to declare them

	while (*line && (*line)[i] != '\n' && (*line)[i] != '\0')// Get line length
		i++;
	while (buf[j] != '\n' && buf[j] != '\0')// Get buffer length
		j++;
	if (!(new = malloc(i + j + 1)))// Allocate line + buffer + 1
		return (-1);
	i = 0;
	j = 0;
	while (*line && (*line)[i] != '\n' && (*line)[i] != '\0')// Copy line
		new[i++] = (*line)[j++];
	j = 0;
	while (buf[j] != '\n' && buf[j] != '\0')// Copy buffer
		new[i++] = buf[j++];
	new[i] = buf[j];// Keep \n or \0 to check if done reading
	i = 0;
	while (buf[j] != '\0')// Rewrite buffer over itself
		buf[i++] = buf[++j];
	free(*line);
	*line = new;// Switch line ptr to new string
	i = 0;
	while ((*line)[i] != '\n' && (*line)[i] != '\0')// Get end of line index
		i++;
	return (i);
}

int			get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1] = "";
	int			ret;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)// Check for errors
		return (-1);
	*line = NULL;
	ret = join_buffer(line, buf, 0, 0);// Get previous run's remaining buffer
	while (ret != -1 && (*line)[ret] != '\n')// Run until error or newline
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) < 1)
			return (ret);// Returns -1 in case of error and 0 in case of EOF
		buf[ret] = '\0';
		ret = join_buffer(line, buf, 0, 0);// Join buffer with line
	}
	if (ret == -1)// This will catch the malloc fails from join
		return (-1);
	(*line)[ret] = '\0';// Replace end of line \n with \0
	return (1);
}
