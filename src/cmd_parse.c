/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:01:21 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/10/24 21:03:03 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_args(int i, char *str)
{
	int		tmp;

	i = ft_strlen(get_data()->cmd1);
	while (str[i])
	{
		if (str[i] != ' ' || str[i] != '	')
		{
			if (str[i] == '"')
			{
				tmp = get_next_char(str, i);
				if (tmp == -1)
					ft_error("Uncompleted quotations\n");

			}
		}
		i++;
	}
	return NULL;
}

int		args_count(char *str)
{
	int		i;
	int		j;
	int		len;
	// int		tmp;

	len = ft_strlen(str);
	i = ft_strlen(get_data()->cmd1);
	j = 0;
	while (str[i])
	{
		printf("\ni = %d.\n", i);
		printf("str is %s.\n", str);
		if (str[i] != ' ' && str[i] != '	')
		{
			printf("Looking at %c.\n", str[i]);
			// if (str[i] == '"')
			// {
			// 	tmp = get_next_char(str, i);
			// 	printf("tmp is %d\n", tmp);
			// 	if (tmp == -1)
			// 		ft_error("Uncompleted quotations\n");
			// 	i += tmp;
			// }
			j++;
			printf("j++, now %d\n", j);
			while (str[i] && str[i] != ' ' && str[i] != '	' && str[i] != 0 && i < len)
			{
				i++;
			}
		}
		i++;
	}
	return (j);
}


char	*get_cmd(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == ' ')
			return (ft_substr(str, 0, i));
		i++;
	}
	return (str);
}
