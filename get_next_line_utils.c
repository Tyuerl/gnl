/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavette <glavette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 02:48:57 by glavette          #+#    #+#             */
/*   Updated: 2022/01/22 23:50:49 by glavette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	count;

	if (s == 0 || *s == 0)
		return (0);
	count = 0;
	while (s && s[count] != '\0' && s[count] != '\n')
		count++;
	if (s[count] == '\n')
		count++;
	return (count);
}

int	ft_check_nl(char *a)
{
	int	i;

	i = 0;
	if (a == 0)
		return (-1);
	while (a[i])
	{
		if (a[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
