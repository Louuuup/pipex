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

//==================COLORS===================//
# define RED "\033[31m"
//==================ERRORS===================//
# define ERR_MAIN "\033[31m\033[1mERROR > \033[0m"
# define ERR_PIPE "Couldn't open the pipe\n"
# define ERR_MOREARG "Need more arguments\n./pipex <f1> <cmd1> <cmd2> <f2>\n"
# define ERR_LESSARG "Need less arguments\n./pipex <f1> <cmd1> <cmd2> <f2>\n"
# define ERR_UNK_CMD "Command unknown or not in usual environment paths.\n"
//==================Structs===================//
typedef struct data
{
	char	*input;
	char	*cmd1;
	char	**args1;
	int		argc1;

	char	*cmd2;
	char	**args2;
	int		argc2;

	char	*output;
	char	**paths;
	int		tmp;

}			t_data;

//
//==================[utils.c]===================//
void	ft_free(void *ptr);
t_data	*get_data(void);
void	ft_error(char *str);
//
//==================[utils1.c]===================//
//
int	get_next_char(char *str, int start);

//==================[parse.c]===================//
void	parse(int argc, char **argv);
void	find_paths(char **env);
//
//================[cmd_parse.c]=================//
char	*get_cmd(char *str);
int		args_count(char *str);
// i is starting point after cmd.
char	**get_args(int i, char *str);
// Returns 1 if no valid path found, else 0.
int		verif_paths(t_data *data);

#endif


// PIPE[2]
// fd[0] = read
// fd[1] = write
