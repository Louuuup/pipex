/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:30:58 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/11/07 14:22:28 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
void	run_cmd(char **cmd, char *valid_path, char **env)
{
	char	*tmp;

	if (!cmd || !valid_path || !env)
		ft_error(ERR_CMD);
	tmp = ft_strjoin(valid_path, cmd[0]);
	if (DEBUG_ON)
		dprintf(STDERR_FILENO, "\n>> RUNNING CMD '%s'\nFull = %s\n", cmd[0], tmp);
	if (execve(tmp, cmd, env) == -1)
		ft_error("execve error\n");

}
void	pipe_in(int fd[2], t_data *data, char **env)
{
	// if (DEBUG_ON)
	// 	printf("fd[0] is %d\nfd[1] is %d\n", fd[0], fd[1]);
	if (DEBUG_ON)
		printf("\nthis is pipe_in\n");
	close(fd[0]);
	if (dup2(data->input_fd, STDIN_FILENO) == -1)
		ft_error(ERR_DUP);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error(ERR_DUP);
	run_cmd(data->cmd->args, data->paths[data->path_idx[0]], env);
	close(fd[1]);
	//free please
}

void pipe_out(int fd[2], t_data *data, char **env)
{
	t_cmd *cmd;

	cmd = NULL;
	if (DEBUG_ON)
		printf("\nthis is pipe_out\n");
	close(fd[1]);
	cmd = data->cmd->next;
	// if (DEBUG_ON)
	// 	printf("fd[0] is %d\nfd[1] is %d\n", fd[0], fd[1]);
	ft_dup2(fd[0], STDIN_FILENO);
	ft_dup2(data->output_fd, STDOUT_FILENO);
	run_cmd(cmd->args, data->paths[data->path_idx[1]], env);
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

	waitpid(pid[0], NULL, 0);

	pid[1] = fork();
	if (pid[1] < 0)
		ft_error(ERR_FORK);
	else if (pid[1] == 0)
		pipe_out(fd, data, env_p);

	close(fd[0]);
	close(fd[1]);

	waitpid(pid[1], NULL, 0);
	if (data->error != NULL)
		ft_error(data->error);
	free_all(data);
	return (NO_ERROR);
}
