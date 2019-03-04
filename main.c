/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 10:23:15 by widraugr          #+#    #+#             */
/*   Updated: 2019/02/26 16:39:14 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		ft_printf("arr = '%s'\n", arr[i]);
		i++;
	}
}

void	ft_open_dir(char *name_dir, t_flag *fl)
{
	DIR				*dir;
	struct dirent	*dirent;
	char			*str;
	char			**arr;

	str = ft_strnew(0);
	if (!(dir = opendir(name_dir)))
	{
		ft_printf("No open %s\n", name_dir);
		return ;
	}
	while ((dirent = readdir(dir)) != NULL)
		if (fl->flag_a == 1)
			str = ft_join_name(str, dirent->d_name, name_dir);
		else
			if (dirent->d_name[0] != '.')
				str = ft_join_name(str, dirent->d_name, name_dir);
	//ft_printf("str = '%s'\n", str);
	ft_printf("\n%s\n", name_dir);
	arr = ft_strsplit(str, ' ');
	print_arr(arr);
	if (fl->flag_bigr)
		ft_stat(arr, fl, ft_open_dir);
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
	short int	i;
	
	i = 0;
	if (!fl->flags)
		while (++i < ac)
			ft_open_dir(av[i], fl);
	else
		ft_flag_handing(fl, ac, av);
}	

int main (int ac, char **av)
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
