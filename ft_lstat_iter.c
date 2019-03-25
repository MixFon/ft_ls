/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat_iter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 10:26:26 by widraugr          #+#    #+#             */
/*   Updated: 2019/03/25 11:18:43 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	*ft_lstat_iter_reg(int ac, char **av)
{
	struct stat	st_buf;
	int			i;
	char		*str_n;

	i = -1;
	str_n = ft_strnew(0);
	while (++i < ac)
	{
		if (lstat(av[i], &st_buf) == -1)
		{
			ft_printf("ft_ls: %s: No such file or directory\n", av[i]);
			continue ;
		}
		if (!S_ISDIR(st_buf.st_mode))
		{
			str_n = ft_strnjoinfree(str_n, av[i]);
			str_n = ft_strnjoinfree(str_n, "|");
		}
	}
	if (*str_n == '\0')
	{
		free(str_n);
		return (NULL);
	}
	return (str_n);
}

void	*ft_lstat_iter_dir(int ac, char **av)
{
	struct stat	st_buf;
	int			i;
	char		*str_n;

	i = -1;
	str_n = ft_strnew(0);
	while (++i < ac)
	{
		if (lstat(av[i], &st_buf) == -1)
		{
			ft_printf("ft_ls: %s: No such file or directory\n", av[i]);
			continue ;
		}
		if (S_ISDIR(st_buf.st_mode))
		{
			str_n = ft_strnjoinfree(str_n, av[i]);
			str_n = ft_strnjoinfree(str_n, "|");
		}
	}
	if (*str_n == '\0')
	{
		free(str_n);
		return (NULL);
	}
	return (str_n);
}
