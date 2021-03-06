/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 11:48:19 by widraugr          #+#    #+#             */
/*   Updated: 2019/03/25 11:18:38 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Получение размера терминала.
*/

int		ft_winsize(void)
{
	struct winsize ws_buf;

	ioctl(0, TIOCGWINSZ, &ws_buf);
	return (ws_buf.ws_col);
}

/*
** Выявление самого длиного слова.
*/

int		ft_lengthy(char **arr)
{
	int len;
	int	temp;

	len = 0;
	temp = 0;
	while (*arr != NULL)
	{
		temp = ft_strlen(ft_last_ndir(*arr));
		if (len < temp)
			len = temp;
		arr++;
	}
	return (len);
}

/*
** Создание новой структуры для выравнивания.
*/

t_ind	*ft_new_ind(char **arr_n)
{
	t_ind *new_ind;

	if (!(new_ind = (t_ind *)malloc(sizeof(t_ind))))
		return (NULL);
	new_ind->col = 0;
	new_ind->len_str = 0;
	new_ind->tabl_col = 0;
	new_ind->count_str = 0;
	new_ind->tabl_str = 0;
	new_ind->col = ft_winsize();
	new_ind->len_str = ft_lengthy(arr_n) + 1;
	new_ind->tabl_col = new_ind->col / new_ind->len_str;
	new_ind->count_str = ft_count_str(arr_n);
	new_ind->tabl_str = new_ind->count_str / new_ind->tabl_col;
	return (new_ind);
}

/*
** Удаляет ытруктуру ind.
*/

void	ft_del_ind(t_ind *ind)
{
	ind->col = 0;
	ind->len_str = 0;
	ind->tabl_col = 0;
	ind->count_str = 0;
	ind->tabl_str = 0;
	free(ind);
	ind = NULL;
}

void	ft_indent(char **arr_n)
{
	t_ind	*ind;
	int		i;
	int		j;

	i = 0;
	ind = ft_new_ind(arr_n);
	if ((ind->count_str % ind->tabl_col) != 0)
		ind->tabl_str++;
	while (i < ind->tabl_str)
	{
		j = 0;
		while (j < ind->tabl_col)
		{
			if (((j * ind->tabl_str) + i) < ind->count_str)
				ft_printf("%-*s", ind->len_str,
						ft_last_ndir(arr_n[(j * ind->tabl_str) + i]));
			else
				ft_printf("%s", " ");
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_del_ind(ind);
}
