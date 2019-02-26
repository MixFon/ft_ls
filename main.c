/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 10:23:15 by widraugr          #+#    #+#             */
/*   Updated: 2019/02/26 15:34:08 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/types.h>
#include <dirent.h>

void	ft_open_dir(char *name_dir, int flag_a)
{
	DIR				*dir;
	struct dirent	*dirent;

	if (!(dir = opendir(name_dir)))
	{
		printf("No open %s\n", name_dir);
		return ;
	}
	while ((dirent = readdir(dir)) != NULL)
		if (flag_a == 1)
			ft_printf("%s\n", dirent->d_name);
		else
		{
			if (dirent->d_name[0] != '.')
				ft_printf("%s\n", dirent->d_name);
		}
	closedir(dir);
}


/*
** Функция считывания флагов.
*/

t_flag	*ft_readflag(int ac, char **av)
{
	t_flag *fl;

	fl = ft_new_list_flag();
	if (*av[1] == '-')
		ft_initialization(fl, av[1]);
	return (fl);
}

/*
** Функция обрадотки флагов.
*/

void	ft_switch(int ac, char **av)
{
	t_flag		*fl;
	short int	i;
	
	i = 0;
	fl = ft_readflag(ac, av);
	if (!fl->flags)
		while (++i < ac)
		{
			ft_printf("%s:\n", av[i]);
			ft_open_dir(av[i], 0);
		}
	else
		ft_flag_handing(fl, ac, av);
	free(fl);
}	

int main (int ac, char **av)
{
	
	if (ac == 1)
		ft_open_dir(".", 0);
	else
		ft_switch(ac, av);
	return (0);
}
