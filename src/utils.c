/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:42:14 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/11/08 14:20:03 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

void	ft_error(char *str)
{
	ft_putstr_fd(ERR_MAIN, STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	perror(ERR_EXP);
	free_all(get_data());
	exit(ERROR);
}

void	my_error(char *str)
{
	ft_putstr_fd(ERR_MAIN, STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	free_all(get_data());
	exit (ERROR);
}

int	get_next_char(char *str, int start)
{
	int	i;

	i = 1;
	if (!str)
		ft_error("unnamed error\n");
	while (str[i + start])
	{
		if (str[i + start] == '"')
			return (i);
		i++;
	}
	return (-1);
}
