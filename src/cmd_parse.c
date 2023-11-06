/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:01:21 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/11/06 14:28:08 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char **get_args(char *str)
{
	char **arr;

	arr = NULL;
	// *arr = NULL;
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
