/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:48:55 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/10/27 14:12:30 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// t_arg	*add_arg(char *arg, t_arg *head)
// {
// 	t_arg	*new;
// 	t_arg	*tmp;

// 	new = ft_calloc(1, sizeof(t_arg));
// 	new->arg = arg;
// 	if (head)
// 	{
// 		tmp = head;
// 		while (tmp->next)
// 			tmp = tmp->next;
// 		head->next = new;
// 	}
// 	else
// 		head = new;
// 	return (head);
// }

// void	*lst_free(t_arg *head)
// {
// 	t_arg	*tmp;

// 	while (head)
// 	{
// 		tmp = head->next;
// 		ft_free(head);
// 		head = tmp;
// 	}
// 	return (NULL);
// }
