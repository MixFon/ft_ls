/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 11:45:05 by widraugr          #+#    #+#             */
/*   Updated: 2019/03/21 11:49:25 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Печатает стрку total.
*/

void	ft_print_total(char **arr)
{
	struct stat		*st_buf;
	size_t			total;

	total = 0;
	while (*arr)
	{
		st_buf = (struct stat *)malloc(sizeof(struct stat));
		if (lstat(*arr, st_buf) < 0)
		{
			arr++;
			continue ;
		}
		if ((st_buf->st_mode & S_IFMT) != S_IFLNK)
			total += st_buf->st_blocks;
		free(st_buf);
		arr++;
	}
	ft_printf("total %d\n", total);
}

/*
** Создает строку содержащую время.
*/

char	*ft_infill_dt_time(char *time)
{
	char *str_time;

	str_time = ft_strnew(5);
	if (ft_strcl(time, '\n') == 4)
		ft_strncpy(str_time, time, 4);
	else
		ft_strncpy(str_time, time, 5);
	return (str_time);
}

/*
** Обрабатывает дату.
*/

void	ft_work_date(t_filds *fild, struct stat *st_buf)
{
	struct tm		*tm_buf;
	char			**date;
	long long int	real_sec;

	fild->major = major(st_buf->st_rdev);
	fild->minor = minor(st_buf->st_rdev);
	date = ft_strsplit(ctime(&st_buf->st_mtime), ' ');
	real_sec = time(NULL);
	fild->mon = ft_strdup(date[1]);
	fild->day = ft_strdup(date[2]);
	if ((real_sec - st_buf->st_mtime) > 15638400)
		fild->time = ft_infill_dt_time(date[4]);
	else
		fild->time = ft_infill_dt_time(date[3]);
	ft_del_arr(date);
	free(date);
}

/*
** Создает новый элемент списка filds и добавляет уго в конец.
*/

t_filds	*ft_stat_line(struct stat *st_buf, char *path,
		struct passwd *pas_buf, t_filds *first_fild)
{
	struct group	*gr_buf;
	t_filds			*fild;
	t_filds			*first;

	first = first_fild;
	fild = ft_create_fild();
	gr_buf = getgrgid(st_buf->st_gid);
	ft_create_rights(fild, st_buf, path);
	fild->links = st_buf->st_nlink;
	fild->users = ft_strdup(pas_buf->pw_name);
	fild->grups = ft_strdup(gr_buf->gr_name);
	fild->size = st_buf->st_size;
	ft_work_date(fild, st_buf);
	fild->name = ft_link_name(st_buf, path);
	if (first_fild == NULL)
		first = fild;
	else
	{
		while (first_fild->next != NULL)
			first_fild = first_fild->next;
		first_fild->next = fild;
	}
	return (first);
}

/*
** При поднятом флаге l создает список из файлов
*/

void	ft_flag_l(char **arr, t_flag *fl)
{
	struct passwd	*pas_buf;
	struct stat		*st_buf;
	t_filds			*filds;

	filds = NULL;
	while (*arr != NULL)
	{
		st_buf = (struct stat *)malloc(sizeof(struct stat));
		if (lstat(*arr, st_buf) < 0)
		{
			ft_printf("%s\n", "eror lstat file ft_flag_l");
			arr++;
			continue ;
		}
		pas_buf = getpwuid(st_buf->st_uid);
		filds = ft_stat_line(st_buf, *arr, pas_buf, filds);
		free(st_buf);
		arr++;
	}
	ft_print_filds(filds, fl);
	if (filds != NULL)
		ft_del_filds(filds);
}
