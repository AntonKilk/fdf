/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:01:12 by akilk             #+#    #+#             */
/*   Updated: 2022/03/14 10:19:36 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* Free the list of pointers */

static void	free_lst(void *content, size_t size)
{
	if (!size)
		return ;
	free(*(char **)content);
	free(content);
}

/*
** We use ft_strsplit() to get rid of delimiters and take only numbers
**  from each row. We place all the map in **nums.
** Each row of **nums map is parsed to integers with atoi() and
**  returned to fill **data;
** We free nums() memory with free_tab().
*/

static int	*str2int(char *str, int w)
{
	char	**nums;
	int		i;
	int		*num_row;

	num_row = (int *)malloc(sizeof(int) * w);
	nums = ft_strsplit(str, ' ');
	free(str);
	i = 0;
	while (nums[i])
	{
		num_row[i] = ft_atoi(nums[i]);
		if (num_row[i] > 999999)
			return (NULL);
		i++;
	}
	ft_free_tab(nums, i);
	return (num_row);
}

/*
** Create array of integers 'data' and fill it with str2int() function.
** To get content of string (i.e. lst->content), we take *(char **),
** so the value of the pointer to pointer of start->content.
** Delete list 'start' and free memory.
*/

static int	**fill_matrix(t_list *start, int h, int w)
{
	int		**data;
	int		i;

	data = malloc(sizeof(int *) * h);
	i = 0;
	while (start)
	{
		data[i] = str2int(*(char **)start->content, w);
		if (!data[i])
			return (NULL);
		start = start->next;
		i++;
	}
	ft_lstdel(&start, free_lst);
	return (data);
}

int	get_width(char *line)
{
	return (ft_count_words(line, ' '));
}

/*
** Read file with get_next_line().
** Instead of the string we add to the list the pointer to string.
** That is to avoid additional operation of copying / freeing.
** Calculate height and width of input file.
*/

int	**read_fdf(int fd, t_fdf *data)
{
	t_list	*start;
	char	*line;
	int		ret;

	data->height = 0;
	start = NULL;
	line = NULL;
	ret = get_next_line(fd, &line);
	if (ret < 0)
		return (NULL);
	data->width = get_width(line);
	while (ret)
	{
		if (get_width(line) != data->width)
			return (NULL);
		ft_lstadd(&start, ft_lstnew(&line, sizeof(char *)));
		data->height++;
		ret = get_next_line(fd, &line);
	}
	ft_lstrev(&start);
	return (fill_matrix(start, data->height, data->width));
}
