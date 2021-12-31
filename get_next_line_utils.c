/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavette <glavette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 02:48:57 by glavette          #+#    #+#             */
/*   Updated: 2021/12/31 17:43:00 by glavette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

int	ft_strlen(char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0' && s[count] != '\n')
		count++;
	return (count);
}
