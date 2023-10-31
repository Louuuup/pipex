/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:42:14 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/10/31 12:45:31 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
	ptr = NULL;
}

// void	free_all(t_data *data)
// {
// 	if (data->argc1 > 0)
// 		ft_free(data->cmd1);
// }

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
	// free_all(get_data());
	exit(ERROR);
}

void	my_error(char *str)
{
	ft_putstr_fd(ERR_MAIN, STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	// free_all(get_data());
	exit (ERROR);
}

char	*ft_strjoin_new(char const *s1, char const *s2)
{
	char	*str_a;
	char	*str_b;
	size_t	size;
	size_t	s1_size;
	size_t	s2_size;

	if (!s1 || !s2)
		return (0);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	size = s1_size + s2_size + 2;
	if (size <= 0)
		return (0);
	str_a = malloc(size * sizeof(char));
	if (!str_a)
		return (NULL);
	str_b = str_a + s1_size;
	ft_memcpy(str_a, s1, s1_size);

	ft_memcpy(str_b, s2, s2_size);
	str_a[size - 1] = '\0';
	return (str_a);
}
