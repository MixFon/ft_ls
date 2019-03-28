/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 10:23:15 by widraugr          #+#    #+#             */
/*   Updated: 2019/03/25 16:44:51 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_arr(char **arr, t_flag *fl)
{
	if (!fl->flag_l)
	{
		if (!fl->flag_1)
			ft_indent(arr);
		else
			while (*arr != NULL)
			{
				ft_printf("%s\n", ft_last_ndir(*arr));
				arr++;
			}
	}
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

	str = ft_bl(name_dir);
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
	if (str == NULL)
	{
		closedir(dir);
		return ;
	}
	arr = ft_sort_print_arr(str, fl);
	if (fl->flag_bigr)
		ft_stat(arr, fl, ft_open_dir);
	ft_del_arr_dir(arr, &dir, &str);
}

/*
** Read flags.
*/

t_flag	*ft_readflag(int ac, char **av)
{
	t_flag	*fl;
	int		i;

	i = 1;
	fl = ft_new_list_flag();
	if (ac >= 2)
		while (i < ac)
		{
			if (*av[i] == '-')
				ft_initialization(fl, av[i]);
			i++;
		}
	return (fl);
}

/*
** Works flags function.
*/

void	ft_switch(t_flag *fl, int ac, char **av)
{
	int	i;

	i = -1;
	av++;
	while (--ac > 0)
	{
		if (**av == '-')
			av++;
		else
			break ;
		if (av == NULL)
			break ;
	}
	ft_flag_handing(fl, ac, av);
}

int		main(int ac, char **av)
{
	t_flag		*fl;

	fl = ft_readflag(ac, av);
	if (fl->flag_error)
	{
		free(fl);
		return (1);
	}
	if (ac == 1)
		ft_open_dir(".", fl);
	else
		ft_switch(fl, ac, av);
	free(fl);
	return (0);
}
