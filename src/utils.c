/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:42:14 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/11/06 15:34:15 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

void	ft_error(char *str)
{
	ft_putstr_fd(ERR_MAIN, STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	perror(ERR_EXP);
	free_all(get_data());
	exit(ERROR);
}

void	my_error(char *str)
{
	ft_putstr_fd(ERR_MAIN, STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	free_all(get_data());
	exit (ERROR);
}

// char	*ft_strjoin_new(char const *s1, char const *s2)
// {
// 	char	*str_a;
// 	char	*str_b;
// 	size_t	size;
// 	size_t	s1_size;
// 	size_t	s2_size;

// 	if (!s1 || !s2)
// 		return (0);
// 	s1_size = ft_strlen(s1);
// 	s2_size = ft_strlen(s2);
// 	size = s1_size + s2_size + 2;
// 	if (size <= 0)
// 		return (0);
// 	str_a = malloc(size * sizeof(char));
// 	if (!str_a)
// 		return (NULL);
// 	str_b = str_a + s1_size;
// 	ft_memcpy(str_a, s1, s1_size);

// 	ft_memcpy(str_b, s2, s2_size);
// 	str_a[size - 1] = '\0';
// 	return (str_a);
// }

int	get_next_char(char *str, int start)
{
	int i;

	i = 1;
	if (!str)
		ft_error("unnamed error\n");
	while (str[i + start])
	{
		if (str[i + start] == '"')
			return (i);
		i++;
	}
	return (-1);

}
