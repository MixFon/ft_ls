/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 10:23:47 by widraugr          #+#    #+#             */
/*   Updated: 2019/03/25 15:39:11 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft_last_ver/ft_printf.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include <time.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <stdio.h>

typedef	struct		s_flag
{
	int				flags;
	int				flag_l;
	int				flag_r;
	int				flag_bigr;
	int				flag_t;
	int				flag_a;
	int				flag_dog;
	int				flag_e;
	int				flag_f;
	int				flag_1;
	int				flag_error;
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
	int				major;
	int				minor;
	char			*xattr;
	char			*acl;
	struct s_filds	*next;
}					t_filds;

typedef struct		s_fsize
{
	int				ln;
	int				us;
	int				gr;
	int				sz;
	int				sma;
	int				smi;
}					t_fsize;

typedef struct		s_ind
{
	int	col;
	int len_str;
	int tabl_col;
	int count_str;
	int	tabl_str;
}					t_ind;

void				ft_flag_handing(t_flag *fl, int ac, char **av);
t_flag				*ft_new_list_flag(void);
void				ft_initialization(t_flag *fl, char *str);
void				ft_open_dir(char *name_dir, t_flag *fl);
char				*ft_join_name(char *str, char *name, char *name_dir);
void				ft_stat(char **arr, t_flag *fl, void (*fcn)(char *,
			t_flag *));
void				ft_del_arr(char **arr);
void				*ft_last_ndir(char *dir);
void				ft_sort_arr(char ***arr, t_flag *fl);
void				ft_flag_l(char **arr, t_flag *fl);
void				ft_type_files(char *rights, struct stat *st_buf);
void				ft_access_rights_user(char *rights, struct stat *st_buf);
void				ft_access_rights_grup(char *rights, struct stat *st_buf);
void				ft_access_rights_all(char *rights, struct stat *st_buf);
t_filds				*ft_create_fild(void);
void				ft_create_rights(t_filds *fild, struct stat *st_buf,
		char *path);
void				ft_print_filds(t_filds *fild, t_flag *fl);
void				ft_del_filds(t_filds *fild);
void				ft_print_total(char **arr);
void				ft_print_arr(char **arr, t_flag *fl);
int					ft_flag_handing_reg(t_flag *fl, int ac, char **av);
void				ft_flag_handing_dir(t_flag *fl, int ac, char **av, int bl);
void				ft_acl(t_filds *fild, char *path);
char				*ft_link_name(struct stat *st_buf, char *path);
void				ft_paragraph(t_filds *fild, t_fsize *fs);
void				ft_indent(char **arr_n);
t_fsize				*ft_new_fsize(void);
void				ft_del_fsize(t_fsize *fs);
size_t				ft_count_str(char **arr);
char				*ft_bl(char *name_dir);
void				ft_del_arr_dir(char **arr, DIR **dir, char **str);
void				*ft_lstat_iter_reg(int ac, char **av);
void				*ft_lstat_iter_dir(int ac, char **av);
char				**ft_sort_print_arr(char *str, t_flag *fl);

#endif
