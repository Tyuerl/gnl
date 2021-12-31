/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavette <glavette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 09:04:51 by glavette          #+#    #+#             */
/*   Updated: 2021/12/31 14:44:23 by glavette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

static char	*ft_check_line(char *str, char *buff, int *counter)
{
	int		i;
	int		end;
	char	*temp;

	i = 0;
	end = ft_strlen(buff);
	temp = malloc (end + *counter + 1);
	if (temp == NULL)
		return (0);
	if (*counter != 0)
	{
		i--;
		while (++i < *counter)
			temp[i] = str[i];
		free(str);
		i = 0;
	}
	while (i < end)
	{
		temp[*counter] = buff[i];
		(*counter)++;
		i++;
	}
	temp[*counter] = buff[end];
	return (temp);
}

static char	*ft_read_line(int fd, char *str, char *buff)
{
	int	reading;
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	reading = read(fd, buff, BUFFER_SIZE);
	buff[reading] = '\0';
	while (reading > 0 && !(flag == 10))
	{
		str = ft_check_line(str, buff, &i);
		if ((str == NULL) || *(str + i) == '\n')
			flag = 10;
		if (flag != 10)
		{
			reading = read(fd, buff, BUFFER_SIZE);
			buff[reading] = '\0';
		}
	}
	if (str != NULL && str[i] == '\n')
		str[i + 1] = 0;
	return (str);
}

char	*get_next_line(int fd)
{
	char	*buff;
	char	*str;

	str = 0;
	buff = malloc (BUFFER_SIZE + 1);
	if (buff == NULL)
		return (0);
	str = ft_read_line(fd, str, buff);
	free(buff);
	return (str);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
