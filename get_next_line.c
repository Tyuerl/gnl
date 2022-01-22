/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavette <glavette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 21:45:48 by glavette          #+#    #+#             */
/*   Updated: 2022/01/22 23:50:52 by glavette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_check_past(char *buff, char *past)
{
	int	i;

	i = -1;
	if (!past)
		return ;
	while (past[++i])
		buff[i] = past[i];
	buff[i] = 0;
	free(past);
	past = 0;
	return ;
}

char	*ft_save_next_line(char *buff, char **past)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (ft_check_nl(buff) < 0)
		return (0);
	i = ft_strlen(buff);
	if (i < BUFFER_SIZE)
	{
		(*past) = malloc(BUFFER_SIZE - i + 1);
		if (*past == 0)
			return (0);
		while (i + j < BUFFER_SIZE)
		{
			*(*(past) + j) = buff[i + j];
			j++;
		}
		*(*(past) + j) = 0;
	}
	buff[i] = 0;
	return (*(past));
}

char	*ft_check_line(char *str, char *buff, int *flag)
{
	int		len;
	char	*new_str;
	int		i;

	i = -1;
	len = ft_strlen(str);
	new_str = malloc (len + ft_strlen(buff) + 1);
	if (new_str == 0)
	{
		*flag = -1;
		return (0);
	}
	while (++i < len)
	new_str[i] = str[i];
	i = -1;
	if (str)
		free (str);
	while (++i < ft_strlen(buff))
		new_str[i + len] = buff[i];
	new_str[i + len] = buff[i];
	if (new_str[i + len - 1] == '\n')
		*(flag) = -1;
	return (new_str);
}

char	*ft_read_line(char	*str, char	*buff, char	**past, int fd)
{
	int	flag;
	int	reading;

	reading = 2;
	flag = 2;
	while (flag > 0 && reading > 0 && fd >= 0)
	{
		*past = ft_save_next_line(buff, past);
		str = ft_check_line(str, buff, &flag);
		if (flag != -1)
		{
			reading = read(fd, buff, BUFFER_SIZE);
			if (reading >= 0)
				buff[reading] = 0;
		}
	}
	free (buff);
	buff = 0;
	if (str && str[0] == 0)
	{
		free(str);
		str = 0;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*past;
	char		*buff;
	char		*str;
	int			flag;
	int			reading;

	str = 0;
	reading = 1;
	flag = 1;
	buff = 0;
	buff = malloc (BUFFER_SIZE + 1);
	if (buff == 0)
		return (0);
	buff[0] = 0;
	ft_check_past(buff, past);
	str = ft_read_line(str, buff, &past, fd);
	return (str);
}
