/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:51:35 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/10/20 10:31:22 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <string.h>
# include <stdio.h>
#include <fcntl.h> ///tmp

//==================VALUES===================//
# define DEBUG_ON 0
# define TRUE 1
# define FALSE 0
# define YES 1
# define NO 0
//==================COLORS===================//
# define RED "\033[31m"
//==================ERRORS===================//
# define ERR_MAIN "\033[31m\033[1mERROR > \033[0m"
# define ERR_EXP "\033[37m\033[1mREASON\033[0m"
# define ERR_PIPE "Couldn't open the pipe\n"
# define ERR_MOREARG "Need more arguments\n./pipex <f1> <cmd1> <cmd2> <f2>\n"
# define ERR_LESSARG "Need less arguments\n./pipex <f1> <cmd1> <cmd2> <f2>\n"
# define ERR_UNK_CMD "Command unknown or not in usual environment paths.\n"
# define ERR_FORK "Forked up!\n"
# define ERR_CMD "Could not run cmd with those args\n"
# define ERR_PATHS "Could not verif paths!\n"
# define ERR_DUP "Dup error\n"
# define ERR_OPEN_I "WRONG INPUT\n"
# define ERR_OPEN_O "WRONG OUTPUT\n"
//==================Structs===================//
typedef struct cmd
{
	char	**args;
	void	*next;
}			t_cmd;

typedef struct data
{
	char	*input;
	int		input_fd;
	char	*output;
	int		output_fd;
	t_cmd	*cmd; //malloc
	int		path_idx[2];
	char	**paths; //malloc
	int		tmp;

}			t_data;

//
//==================[utils.c]===================//
t_data	*get_data(void);
void	ft_error(char *str);
void	my_error(char *str);
int		get_next_char(char *str, int start);
//
//==================[utils1.c]===================//
void	ft_free(void *ptr);
void	free_all(t_data *data);
t_cmd	*add_lst(t_cmd *cmd);
void	*lst_free(t_cmd *cmd);
void	arr_free(void **arr);
//
//==================[parse.c]===================//
void	parse(int argc, char **argv, char **env);
void	find_paths(char **env);
//
//================[cmd_parse.c]=================//
char	**get_args(char *str);
// Returns -1 if no valid path found, else 0.
int		verif_paths(char *cmd, t_data *data);
void	ft_open(t_data *data);
//
//================[error_handler.c]=================//
void	ft_dup2(int fd, int std);

#endif


// PIPE[2]
// fd[0] = read
// fd[1] = write
