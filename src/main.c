/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:30:58 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/10/31 12:56:48 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_cmd(char *cmd, char **args, char *valid_path, char **env)
{
	char	*tmp;

	if (!cmd || !valid_path || !env)
		ft_error(ERR_CMD);
	tmp = ft_strjoin(valid_path, cmd);
	if (args == NULL)
		execve(tmp, &cmd, env);
	else
		execve(tmp, args, env);

	ft_free(tmp);
}
void	pipe_in(int fd[2], t_data *data, char **env)
{
		printf("fd[0] is %d\nfd[1] is %d\n", fd[0], fd[1]);
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
		{
			write(1,"*", 1);
			ft_error(ERR_DUP);
		}
		run_cmd(data->cmd1, data->args1, data->paths[data->path_idx[0]], env);
		close(fd[1]);
		//free please
}

void pipe_out(int fd[2], t_data *data, char **env)
{
	close(fd[1]);
	printf("fd[0] is %d\nfd[1] is %d\n", fd[0], fd[1]);
	ft_dup2(fd[0], STDIN_FILENO);
	run_cmd(data->cmd2, data->args2, data->paths[data->path_idx[1]], env);
}

int	main(int argc, char *argv[], char **env_p)
{
	t_data	*data;
	int		fd[2];
	int		pid[2];

	data = get_data();
	parse(argc, argv, env_p);
	if (pipe(fd) == -1)
		ft_error(ERR_PIPE);

	pid[0] = fork();
	if (pid[0] < 0)
		ft_error(ERR_FORK);
	else if (pid[0] == 0)
		pipe_in(fd, data, env_p);


	pid[1] = fork();
	if (pid[1] < 0)
		ft_error(ERR_FORK);
	else if (pid[1] == 0)
		pipe_out(fd, data, env_p);

	close(fd[0]);
	close(fd[1]);

	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	ft_free(data->paths);
	return (NO_ERROR);
}
