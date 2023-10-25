/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:04:43 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/10/24 19:18:59 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_next_char(char *str, int start)
{
	int i;

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
