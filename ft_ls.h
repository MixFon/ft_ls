/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 10:23:47 by widraugr          #+#    #+#             */
/*   Updated: 2019/02/26 16:39:17 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H

#include "libft_last_ver/ft_printf.h"
#include <sys/types.h>
#include <time.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>

typedef	struct		s_flag
{
	int				flags;
	int				flag_l;
	int				flag_r;
	int				flag_bigr;
	int				flag_t;
	int				flag_a;
}					t_flag;

typedef struct		s_filds
{
	char			*rights;
	int				links;
	char			*users;
	char			*grups;
	size_t			size;
	char			*mon;
	char			*day;
	char			*time;
	char			*name;
	struct s_filds	*next;
}					t_filds;

void	ft_flag_handing(t_flag *fl, int ac, char **av);
t_flag	*ft_new_list_flag(void);
void	ft_initialization(t_flag *fl, char *str);
void	ft_open_dir(char *, t_flag *);
char	*ft_join_name(char *str, char *name, char *name_dir);
void	ft_stat(char **arr, t_flag *fl, void (*fcn)(char *, t_flag *));
void	ft_del_arr(char **arr);
void	*ft_last_ndir(char *dir);
void	ft_sort_arr(char ***arr, t_flag *fl);
void	ft_flag_l(char **arr, t_flag *fl);
void	ft_type_files(char *rights, struct stat *st_buf);
void	ft_access_rights_user(char *rights, struct stat *st_buf);
void	ft_access_rights_grup(char *rights, struct stat *st_buf);
void	ft_access_rights_all(char *rights, struct stat *st_buf);
t_filds	*ft_create_fild(void);
void	ft_create_rights(t_filds *fild, struct stat *st_buf);
void	ft_print_filds(t_filds *fild);
void	ft_del_filsa(t_filds *fild);

#endif
