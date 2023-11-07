/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:01:21 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/11/07 15:11:10 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char **get_args(char *str)
{
	char **arr;

	arr = NULL;
	if (!str)
		return (NULL);
	if (!ft_has_space(str))
	{
		if (DEBUG_ON)
			printf("str (%s) has no space\n", str);
		arr = (char **)ft_calloc(2, sizeof(char *));
		arr[0] = ft_strdup(str);
		return (arr);
	}
	else
		arr = ft_split(str, ' ');
	return (arr);
}

void	open_fd(t_data *data)
{
	data->input_fd = ft_open(data->input, F_INPUT);
	data->output_fd = ft_open(data->output, F_OUTPUT);
	if (DEBUG_ON)
		printf("FD_IN = %d\nFD_OUT = %d\n", data->input_fd, data->output_fd);
	if (data->input_fd == -1)\
	{
		err_resume(ERR_OPEN_I);
		data->input_fd = get_devnull();
	}
	if (data->output_fd == -1)
		ft_error(ERR_OPEN_O);
}

int	ft_open(char *file, int file_type)
{
	int fd;

	if (file_type == F_INPUT)
	{
		if (access(file, R_OK) == ERROR)
		{
			err_resume(ERR_READ_I);
			get_data()->invalid_input = 1;
			return (get_devnull());
		}
		fd = open(file, O_RDONLY);
	}
	else if (file_type == F_OUTPUT)
	{
		if (access(file, R_OK) == ERROR)
			ft_error(ERR_READ_O);
		if (access(file, W_OK) == ERROR)
			ft_error(ERR_WRITE_O);
		fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	}
	else
		fd = ERROR;
	return (fd);
}

// int		args_count(int i, char *str)
// {
// 	int	i;
// 	int	j;
// 	int in_quote;

// 	in_quote = 0;
// 	j = 0;
// 	printf("Whole str is %s\n", str);
// 	while (str[i])
// 	{
// 		// if (str[i] == '"')
// 		// {
// 		// 	i++;
// 		// 	in_quote = !in_quote;
// 		// }
// 		if ((str[i] == ' ' || str[i] == '	') && !in_quote)
// 			i++;
// 		else
// 		{
// 			j++;
// 			while (str[i] && str[i] != ' ')
// 				i++;
// 		}
// 	}
// 	return (j);
// }
// {
// 	int		i;
// 	int		j;
// 	int		len;
// 	// int		tmp;

// 	len = ft_strlen(str);
// 	i = ft_strlen(get_data()->cmd1);
// 	j = 0;
// 	while (str[i])
// 	{
// 		printf("\ni = %d.\n", i);
// 		printf("str is %s.\n", str);
// 		if (str[i] != ' ' && str[i] != '	')
// 		{
// 			// if (str[i] == '"')
// 			// {
// 			// 	tmp = get_next_char(str, i);
// 			// 	printf("tmp is %d\n", tmp);
// 			// 	if (tmp == -1)
// 			// 		ft_error("Uncompleted quotations\n");
// 			// 	i += tmp;
// 			// }
// 			j++;
// 			printf("j++, now %d\n", j);
// 			while (str[i] && str[i] != ' ' && str[i] != '	' && str[i] != 0 && i < len)
// 			{
// 				i++;
// 			}
// 		}
// 		i++;
// 	}
// 	return (j);
// }


// char	*get_cmd(char *str)
// {
// 	int i;

// 	i = 0;
// 	if (!str)
// 		return (NULL);
// 	while (str[i])
// 	{
// 		if (str[i] == ' ')
// 			return (ft_substr(str, 0, i));
// 		i++;
// 	}
// 	return (str);
// }
