/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:18:06 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/10/30 17:02:37 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse(int argc, char **argv, char **env)
{
	t_data *data;

	data = get_data();
	if (argc > 5)
		my_error(ERR_LESSARG);
	else if (argc < 5)
		my_error(ERR_MOREARG);
	data->input = argv[1];
	if (ft_has_space(argv[2]) > 0)

	data->cmd1 = argv[2];
	data->cmd2 = argv[3];
	data->output = argv[4];
	find_paths(env);
	if (get_args_a(argv[2]) || get_args_b(argv[3]))
		my_error(ERR_MOREARG);
	data->path_idx[0] = verif_paths(data->cmd1, data);
	data->path_idx[1] = verif_paths(data->cmd2, data);
	if (data->path_idx[0] == -1 || data->path_idx[1] == -1)
		ft_error(ERR_UNK_CMD);
}

void	find_paths(char **env)
{
	t_data	*data;
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
	data->paths[0] = ft_strtrim(data->paths[0], "PATHS=");
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
		// printf("tmp = %s\n", tmp);
		// printf("access status = %d\n", access(tmp, F_OK));
		if (access(tmp, F_OK) == 0)
			return (i);
		free(tmp);
		i++;
	}
	return -1;
}


