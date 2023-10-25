/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:30:58 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/10/24 20:18:24 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char **env_p)
{
	t_data	*data;
	// int	fd[2];
	// int id;
	data = get_data();
	parse(argc, argv);
	find_paths(env_p);
	data->cmd1 = get_cmd(argv[2]);
	if (verif_paths(data) == 1)
		ft_error(ERR_UNK_CMD);
	printf("first cmd is %s\n", data->cmd1);
	printf("There is %d args\n", args_count(argv[2]));
	// if (pipe(fd) == -1)
	// 	ft_error(ERR_PIPE);
	// id = fork();
	// tmp = ft_strjoin(data->paths[3], data->cmd1);
	// execve(data->cmd1, arr, env_p);
	ft_free(data->paths);
	return (NO_ERROR);
}
