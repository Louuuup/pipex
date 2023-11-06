/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:04:43 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/11/06 14:35:42 by ycyr-roy         ###   ########.fr       */
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

t_cmd	*add_lst(t_cmd *cmd)
{
	t_cmd	*new;

	new = ft_calloc(1, sizeof(t_cmd));
	cmd->next = new;
	return (new);
}

void	*lst_free(t_cmd *cmd)
{
	t_cmd	*tmp;

	while (cmd)
	{
		tmp = cmd->next;
		arr_free((void *)cmd->args);
		ft_free(cmd);
		cmd = tmp;
	}
	return (NULL);
}

void	arr_free(void **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		ft_free(arr[i]);
		i++;
	}
	ft_free(arr);
}
