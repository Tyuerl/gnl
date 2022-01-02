/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavette <glavette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 02:48:57 by glavette          #+#    #+#             */
/*   Updated: 2022/01/02 15:00:13 by glavette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

int	ft_strlen(char *s)
{
	int	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count] != '\0' && s[count] != '\n')
		count++;
	return (count);
}
