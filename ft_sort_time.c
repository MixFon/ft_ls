/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:16:38 by widraugr          #+#    #+#             */
/*   Updated: 2019/03/25 16:44:56 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_compare(char *name)
{
	struct stat st_buf;

	if (lstat(name, &st_buf) == -1)
		ft_printf("Not access to file  %s\n", name);
	return (st_buf.st_mtime);
}

void	ft_sort_time(char ****arr)
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
			if (ft_compare((**arr)[j]) < ft_compare((**arr)[j + 1]))
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
