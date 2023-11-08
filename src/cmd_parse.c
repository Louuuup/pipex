/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:01:21 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/11/08 14:27:44 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_args(char *str)
{
	char	**arr;

	arr = NULL;
	if (!str)
		return (NULL);
	if (!ft_has_space(str))
	{
		if (DEBUG_ON)
			printf("str (%s) has no space\n", str);
		arr = (char **)ft_calloc(2, sizeof(char *));
		arr[0] = ft_strdup(str);
		return (arr);
	}
	else
		arr = ft_split(str, ' ');
	return (arr);
}

void	open_fd(t_data *data)
{
	data->input_fd = ft_open(data->input, F_INPUT);
	data->output_fd = ft_open(data->output, F_OUTPUT);
	if (DEBUG_ON)
		printf("FD_IN = %d\nFD_OUT = %d\n", data->input_fd, data->output_fd);
	if (data->input_fd == -1)
	{
		err_resume(ERR_OPEN_I);
		data->input_fd = get_devnull();
	}
	if (data->output_fd == -1)
		ft_error(ERR_OPEN_O);
}

int	ft_open(char *file, int file_type)
{
	int	fd;

	if (file_type == F_INPUT)
	{
		if (access(file, R_OK) == ERROR)
		{
			err_resume(ERR_READ_I);
			get_data()->invalid_input = 1;
			return (get_devnull());
		}
		fd = open(file, O_RDONLY);
	}
	else if (file_type == F_OUTPUT)
	{
		if (access(file, R_OK) == ERROR && access(file, F_OK) != ERROR)
			ft_error(ERR_READ_O);
		if (access(file, W_OK) == ERROR && access(file, F_OK) != ERROR)
			ft_error(ERR_WRITE_O);
		fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	}
	else
		fd = ERROR;
	return (fd);
}
