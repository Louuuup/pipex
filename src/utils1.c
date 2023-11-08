/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:04:43 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/11/08 14:20:17 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
	ptr = NULL;
}

void	free_all(t_data *data)
{
	if (data->cmd != NULL)
		lst_free(data->cmd);
	if (data->paths)
		arr_free((void *)data->paths);
	if (data->input_fd != -1)
		close(data->input_fd);
	if (data->output_fd != -1)
		close(data->output_fd);
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
		if (cmd->args != NULL)
			arr_free((void *)cmd->args);
		ft_free(cmd);
		if (tmp)
			cmd = tmp;
		else
			break ;
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
