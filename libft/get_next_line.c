/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:13:38 by akilk             #+#    #+#             */
/*   Updated: 2022/03/02 12:19:57 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	join_line(char **line, char *buf)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strjoin(*line, buf);
	ft_strdel(&tmp);
}

int	seek_new_line(char **line, char *remainder)
{
	char		*p_n;

	p_n = ft_strchr(remainder, '\n');
	if (p_n)
	{
		*p_n = '\0';
		join_line(line, remainder);
		ft_memmove(remainder, p_n + 1, BUFF_SIZE - (p_n - remainder));
		return (1);
	}
	return (0);
}

int	return_status(char **line, char **remainder, int ret, int fd)
{
	if (ret < 0)
	{
		ft_strdel(line);
		ft_strdel(&remainder[fd]);
		return (-1);
	}
	else if (ret == 0)
	{
		ft_strdel(&remainder[fd]);
	}
	if (ft_strlen(*line))
		return (1);
	else
	{
		ft_strdel(line);
		return (0);
	}
}

int	get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*remainder[MAX_FD];

	if (fd < 0 || fd >= MAX_FD || !line || BUFF_SIZE < 1)
		return (-1);
	*line = ft_memalloc(1);
	if (remainder[fd] == NULL)
		remainder[fd] = ft_memalloc(BUFF_SIZE + 1);
	ret = 1;
	while (1)
	{
		if (seek_new_line(line, remainder[fd]))
			return (1);
		else
		{
			join_line(line, remainder[fd]);
			ret = read(fd, remainder[fd], BUFF_SIZE);
			if (ret == -1)
				break ;
			remainder[fd][ret] = '\0';
			if (ret == 0)
				break ;
		}
	}
	return (return_status(line, &remainder[fd], ret, fd));
}
