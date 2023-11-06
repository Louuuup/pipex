/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:33:56 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/11/06 12:36:18 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_dup2(int fd, int std)
{
	int	err;

	err = dup2(fd, std);

	// printf("yo\n");
	if (err == -1)
	{
		write(1,"*", 1);
		ft_error(ERR_DUP);
	}
	close(fd);
}
