/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:08:12 by widraugr          #+#    #+#             */
/*   Updated: 2019/02/26 16:39:16 by widraugr         ###   ########.fr       */
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
	return (new_fl);
}

/*
** Создает дыумерный массив из имен папок.
** Переписать функцию для ускорения работы.
*/

char	*ft_join_name(char *str, char *name, char *name_dir)
{
	char	*ptr;

	//ft_printf("str = %s\n", str);
	if(!(ptr = ft_multi_strdup(5, str, name_dir, "/", name, "|")))
		return (NULL);
	free(str);
	//ft_printf("ptr = %s\n", ptr);
	//str = ft_strnjoinfree(str, name_dir);
	//str = ft_strnjoinfree(str, "/");
	//str = ft_strnjoinfree(str, name);
	//str = ft_strnjoinfree(str, "|");
	return (ptr);
}

/*
** Удаляет массив имен.
*/

void	ft_del_arr(char **arr)
{
	while (*arr != NULL)
	{
		free(*arr);
		*arr = NULL;
		arr++;
	}
}

/*
** Функция печатает содержимое флага.
** Удалить эту функцию!!!!.
*/

void	ft_print_flag(t_flag *fl)
{
	ft_printf("Flag l = %d\n", fl->flag_l);
	ft_printf("Flag r = %d\n", fl->flag_r);
	ft_printf("Flag R = %d\n", fl->flag_bigr);
	ft_printf("Flag a = %d\n", fl->flag_a);
	ft_printf("Flag t = %d\n", fl->flag_t);
	ft_printf("Flags = %d\n", fl->flags);
}

/*
** Инициализирует структуру стандартными занчениями.
*/

void	ft_initialization(t_flag *fl, char *str)
{
	if(ft_strchr(str, 'l'))
		fl->flag_l = 1;
	if(ft_strchr(str, 'r'))
		fl->flag_r = 1;
	if(ft_strchr(str, 'R'))
		fl->flag_bigr = 1;
	if(ft_strchr(str, 'a'))
		fl->flag_a = 1;
	if(ft_strchr(str, 't'))
		fl->flag_t = 1;
	if(ft_strchr(str, '@'))
		fl->flag_dog = 1;
	if(ft_strchr(str, 'e'))
		fl->flag_e = 1;
	if(ft_strchr(str, 'f'))
		fl->flag_f = 1;
	fl->flags = 1;
	//ft_print_flag(fl);
}
