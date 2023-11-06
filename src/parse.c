/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:32:23 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/11/06 13:22:57 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
void	init(t_data *data, char **argv)
{
	t_cmd	*tmp;

	data->input = argv[1];
	tmp = ft_calloc(1, sizeof(t_cmd *));
	data->cmd = tmp;
	data->cmd->args = get_args(argv[2]);
	tmp = add_lst(tmp);
	tmp->args = get_args(argv[3]);
	data->output = argv[4];

}
void	parse(int argc, char **argv, char **env)
{
	t_data	*data;
	t_cmd	*tmp;

	data = get_data();
	init(data, argv);
	tmp = data->cmd->next;
	if (argc > 5)
		my_error(ERR_LESSARG);
	else if (argc < 5)
		my_error(ERR_MOREARG);
	find_paths(env);
	// print_grid(data->cmd->args); /////
	data->path_idx[0] = verif_paths(data->cmd->args[0], data);
	data->path_idx[1] = verif_paths(tmp->args[0], data);
	if (data->path_idx[0] == -1 || data->path_idx[1] == -1)
		ft_error(ERR_UNK_CMD);
	if (DEBUG_ON)
		printf(">Path_idxs:\n[0] is %d\n[1] is %d\n\n", data->path_idx[0], data->path_idx[1]);
}

void	find_paths(char **env)
{
	t_data	*data;
	char	*tmp;
	int		i;

	i = 0;
	data = get_data();
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
			break ;
		i++;
	}
	// printf("found %s\n", env[i]);
	data->paths = ft_split(env[i], ':');
	tmp = data->paths[0];
	data->paths[0] = ft_strtrim(tmp, "PATHS=");
	ft_free(tmp);
	i = 0;
	while (data->paths[i])
	{
		data->paths[i] = charjoinfree(data->paths[i], '/');
		i++;
	}
}

int	verif_paths(char *cmd, t_data *data)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!data->paths)
		ft_error(ERR_PATHS);
	while (data->paths[i])
	{
		tmp = ft_strjoin(data->paths[i], cmd);
		if (access(tmp, F_OK) == 0)
		{
			if (DEBUG_ON)
				printf("Path #%d(%s) working\n", i, tmp);
			ft_free(tmp);
			return (i);
		}
		ft_free(tmp);
		i++;
	}
	return (-1);
}
