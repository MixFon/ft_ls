/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 10:23:47 by widraugr          #+#    #+#             */
/*   Updated: 2019/02/26 15:34:11 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H

#include "libft_last_ver/ft_printf.h"

typedef	struct	s_flag
{
	int			flags;
	int			flag_l;
	int			flag_r;
	int			flag_bigr;
	int			flag_t;
	int			flag_a;

}				t_flag;

void	ft_flag_handing(t_flag *fl, int ac, char **av);
t_flag	*ft_new_list_flag(void);
void	ft_initialization(t_flag *fl, char *str);
/*
void	ft_flag_l(int ac, char **av);
void	ft_flag_r(int ac, char **av);
void	ft_flag_bigr(int ac, char **av);
void	ft_flag_t(int ac, char **av);
void	ft_flag_a(int ac, char **av);
*/
#endif
