/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavette <glavette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 09:04:51 by glavette          #+#    #+#             */
/*   Updated: 2022/01/02 20:25:05 by glavette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

char	*ft_fresher(char	*str)
{
	free(str);
	return (NULL);
}

int	ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	i;

	if (dst == 0 || src == 0 || dstsize == 0)
		return (ft_strlen(src));
	i = -1;
	while (src[++i] && i < dstsize - 1)
		dst[i] = src[i];
	dst[i] = '\0';
	return (ft_strlen(src));
}

static char	*ft_check_line(char *str, char *buff, int *counter)
{
	int		i;
	int		end;
	char	*temp;

	i = 0;
	end = ft_strlen(buff);
	temp = malloc (end + *counter + 1);
	if (temp == NULL || buff == NULL)
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

static char	*ft_read_line(int fd, char *str, char *buff, char *remem)
{
	int	reading;
	int	i;
	int	flag;

	flag = 0;
	reading = 2;
	i = 0;
	while (reading > 0 && !(flag == 10))
	{
		str = ft_check_line(str, buff, &i);
		if ((str == NULL) || *(str + i) == '\n')
			flag = 10;
		if (flag != 10)
		{
			reading = read(fd, buff, BUFFER_SIZE);
			buff[reading] = '\0';
			if (reading < 0)
				str = ft_fresher(str);
			if (reading <= 0 && fd != 0)
				remem = ft_fresher(remem);
		}
	}
	if (str != NULL && str[i] == '\n')
		str[i + 1] = 0;
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*str;
	int			i;
	int			j;
	static char	*temp;

	j = -1;
	str = 0;
	i = ft_strlen(temp) + 1;
	buff = malloc (BUFFER_SIZE + 1);
	if (buff == NULL)
		return (0);
	if (temp == NULL && fd != 0)
		temp = malloc (BUFFER_SIZE + 1);
	else if (fd != 0)
	{
		while (i + ++j < BUFFER_SIZE + 1 && buff[j])
			buff[j] = temp[i + j];
	}
	if (temp == NULL)
		return (ft_fresher(buff));
	str = ft_read_line(fd, str, buff, temp);
	ft_strlcpy(temp, buff, BUFFER_SIZE);
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
