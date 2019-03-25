/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 10:23:15 by widraugr          #+#    #+#             */
/*   Updated: 2019/03/25 09:22:13 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_arr(char **arr, t_flag *fl, char *name_dir)
{
	int			i;
	static int	bl = 0;

	i = 0;
	if (!fl->flag_l)
		ft_indent(arr);
	else
	{
		ft_print_total(arr);
		ft_flag_l(arr, fl);
	}
}

void	ft_open_dir(char *name_dir, t_flag *fl)
{
	DIR				*dir;
	struct dirent	*dirent;
	char			*str;
	char			**arr;
	static int		bl = 0;

	if (bl)
		ft_printf("\n%s:\n", name_dir);
	bl = 1;
	str = NULL;
	if (!(dir = opendir(name_dir)))
	{
		ft_printf("ft_ls: %s: Permission denied\n", name_dir);
		return ;
	}
	while ((dirent = readdir(dir)) != NULL)
		if (fl->flag_a == 1 || fl->flag_f == 1)
			str = ft_join_name(str, dirent->d_name, name_dir);
		else	if (dirent->d_name[0] != '.')
			str = ft_join_name(str, dirent->d_name, name_dir);
	arr = ft_strsplit(str, '|');
	free(str);
	ft_sort_arr(&arr, fl);
	ft_print_arr(arr, fl, name_dir);
	if (fl->flag_bigr)
		ft_stat(arr, fl, ft_open_dir);
	ft_del_arr(arr);
	free(arr);
	closedir(dir);
}

/*
** Функция считывания флагов.
*/

t_flag	*ft_readflag(int ac, char **av)
{
	t_flag *fl;

	fl = ft_new_list_flag();
	if (ac >= 2)
		if (*av[1] == '-')
			ft_initialization(fl, av[1]);
	return (fl);
}

/*
** Функция обрадотки флагов.
*/

void	ft_switch(t_flag *fl, int ac, char **av)
{
	int	i;

	i = 0;
	if (!fl->flags)
		ft_flag_handing(fl, ac + 1, av - 1);
	else
		ft_flag_handing(fl, ac, av);
}

int		ain(int ac, char **av)
{
	t_flag		*fl;

	fl = ft_readflag(ac, av);
	if (ac == 1)
		ft_open_dir(".", fl);
	else
		ft_switch(fl, ac, av);
	free(fl);
	return (0);
}
