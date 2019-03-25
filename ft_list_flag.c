/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:08:12 by widraugr          #+#    #+#             */
/*   Updated: 2019/03/25 15:39:05 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_flag	*ft_new_list_flag(void)
{
	t_flag *new_fl;

	if (!(new_fl = (t_flag *)malloc(sizeof(t_flag))))
		return (NULL);
	new_fl->flag_l = 0;
	new_fl->flag_r = 0;
	new_fl->flag_bigr = 0;
	new_fl->flag_t = 0;
	new_fl->flag_a = 0;
	new_fl->flags = 0;
	new_fl->flag_dog = 0;
	new_fl->flag_e = 0;
	new_fl->flag_f = 0;
	new_fl->flag_1 = 0;
	new_fl->flag_error = 0;
	return (new_fl);
}

char	*ft_join_name(char *str, char *name, char *name_dir)
{
	char	*ptr;

	if (!(ptr = ft_multi_strdup(5, str, name_dir, "/", name, "|")))
		return (NULL);
	free(str);
	return (ptr);
}

/*
** Delete arr names.
*/

void	ft_del_arr(char **arr)
{
	char **first_ptr;

	first_ptr = arr;
	while (*arr != NULL)
	{
		free(*arr);
		*arr = NULL;
		arr++;
	}
}

int		ft_print_error(char *str)
{
	while (*(++str) != '\0')
		if (!ft_strchr("lrRat@ef1", *str))
		{
			ft_printf("ft_ls: illegal option -- %c\n", *str);
			ft_printf("usage: ls [-lrRat@ef1] [file ...]\n");
			return (0);
		}
	return (1);
}

/*
** Init standart value.
*/

void	ft_initialization(t_flag *fl, char *str)
{
	if (ft_strchr(str, 'l'))
		fl->flag_l = 1;
	if (ft_strchr(str, 'r'))
		fl->flag_r = 1;
	if (ft_strchr(str, 'R'))
		fl->flag_bigr = 1;
	if (ft_strchr(str, 'a'))
		fl->flag_a = 1;
	if (ft_strchr(str, 't'))
		fl->flag_t = 1;
	if (ft_strchr(str, '@'))
		fl->flag_dog = 1;
	if (ft_strchr(str, 'e'))
		fl->flag_e = 1;
	if (ft_strchr(str, 'f'))
		fl->flag_f = 1;
	if (ft_strchr(str, '1'))
		fl->flag_1 = 1;
	if (!ft_print_error(str))
		fl->flag_error = 1;
	fl->flags = 1;
}
