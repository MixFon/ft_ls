/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_handing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:34:25 by widraugr          #+#    #+#             */
/*   Updated: 2019/03/21 11:49:30 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Печатает директорию согласно флагам.
*/

void	ft_flag_handing(t_flag *fl, int ac, char **av)
{
	int bl;

	bl = 0;
	if (*av == NULL)
		ft_open_dir(".", fl);
	else
	{
		bl = ft_flag_handing_reg(fl, ac, av);
		ft_flag_handing_dir(fl, ac, av, bl);
	}
}

/*
** Считате количество слов.
*/

size_t	ft_count_str(char **arr)
{
	size_t	count;

	count = 0;
	while (arr[count] != NULL)
		count++;
	return (count);
}

/*
** Сортирует двумерный массив по алфавиту.
*/

void	ft_sort_ascending(char ****arr)
{
	ssize_t	count;
	char	*temp;
	int		i;
	int		j;

	i = 0;
	count = ft_count_str(**arr);
	while (i < count - 1)
	{
		j = 0;
		while (j < count - i - 1)
		{
			if (ft_strcmp((**arr)[j], (**arr)[j + 1]) > 0)
			{
				temp = (**arr)[j];
				(**arr)[j] = (**arr)[j + 1];
				(**arr)[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_sort_descending(char ****arr)
{
	ssize_t	count;
	char	*temp;
	int		i;
	int		j;

	i = 0;
	count = ft_count_str(**arr);
	while (i < count - 1)
	{
		j = 0;
		while (j < count - i - 1)
		{
			if (ft_strcmp((**arr)[j], (**arr)[j + 1]) < 0)
			{
				temp = (**arr)[j];
				(**arr)[j] = (**arr)[j + 1];
				(**arr)[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_sort_arr(char ***arr, t_flag *fl)
{
	if (ft_count_str(*arr) == 0)
		return ;
	if (fl->flag_f)
		return ;
	if (fl->flag_r)
		ft_sort_descending(&arr);
	else
		ft_sort_ascending(&arr);
}
