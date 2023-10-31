/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:01:21 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/10/27 14:12:32 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_args_a(char *str)
{
	t_data *data;
	char **arr;

	if (!str)
		return (1);
	data = get_data();
	if (!ft_has_space(str))
	{
		data->cmd1 = str;
		return (0);
	}
	else
		arr = ft_split(str, ' ');
	data->args1 = arr;
	data->cmd1 = arr[0];
	return (0);
}
int	get_args_b(char *str)
{
	t_data *data;
	char **arr;

	if (!str)
		return (1);
	data = get_data();
	if (!ft_has_space(str))
	{
		data->cmd2 = str;
		return (0);
	}
	else
		arr = ft_split(str, ' ');
	data->args2 = arr;
	data->cmd2 = arr[0];
	return (0);
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
