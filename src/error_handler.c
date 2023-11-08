/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:33:56 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/11/08 14:18:39 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_dup2(int fd, int std)
{
	int	err;

	err = dup2(fd, std);
	if (err == -1)
	{
		write(1, "*", 1);
		ft_error(ERR_DUP);
	}
	close(fd);
}

void	err_resume(char *str)
{
	t_data	*data;

	data = get_data();
	if (data->error)
	{
		ft_free(data->error);
		data->error = NULL;
	}
	data->error = ft_strdup(str);
}

int	get_devnull(void)
{
	int	fd;

	fd = open(VOID, O_RDONLY);
	return (fd);
}
