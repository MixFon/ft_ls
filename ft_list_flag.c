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
	return (new_fl);
}

/*
** Инициализирует структуру стандартными занчениями.
*/

void	ft_initialization(t_flag *fl, char *str)
{
	if(ft_strchr(str, 'l'))
		fl->flag_l = 1;
	ft_printf("Flag l = %d\n", fl->flag_l);
	if(ft_strchr(str, 'r'))
		fl->flag_r = 1;
	ft_printf("Flag r = %d\n", fl->flag_r);
	if(ft_strchr(str, 'R'))
		fl->flag_bigr = 1;
	ft_printf("Flag R = %d\n", fl->flag_bigr);
	if(ft_strchr(str, 'a'))
		fl->flag_a = 1;
	ft_printf("Flag a = %d\n", fl->flag_a);
	if(ft_strchr(str, 't'))
		fl->flag_t = 1;
	ft_printf("Flag t = %d\n", fl->flag_t);
	fl->flags = 1;
	ft_printf("Flags = %d\n", fl->flags);
}