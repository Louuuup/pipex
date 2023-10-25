/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:18:06 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/10/24 18:57:41 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse(int argc, char **argv)
{
	t_data *data;

(void)argc;
	data = get_data();
	if (argc > 5)
		ft_error(ERR_LESSARG);
	else if (argc < 5)
		ft_error(ERR_MOREARG);
	data->input = argv[1];
	if (ft_has_space(argv[2]) > 0)

	data->cmd1 = argv[2];
	data->cmd2 = argv[3];
	data->output = argv[4];
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
	printf("found %s\n", env[i]);
	data->paths = ft_split(env[i], ':');
	data->paths[0] = ft_strtrim(data->paths[0], "PATHS=");
	i = 0;
	while (data->paths[i])
	{
		data->paths[i] = charjoinfree(data->paths[i], '/');
		i++;
	}
}

int	verif_paths(t_data *data)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!data->paths)
		ft_error("a\n");
	while (data->paths[i])
	{
		tmp = ft_strjoin(data->paths[i], data->cmd1);
		printf("tmp = %s\n", tmp);
		printf("access status = %d\n", access(tmp, F_OK));
		if (access(tmp, F_OK) == 0)
			return (0);
		free(tmp);
		i++;
	}
	return 1;
}


