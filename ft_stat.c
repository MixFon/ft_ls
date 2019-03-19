
#include "ft_ls.h"

int		ft_chack_parent_dir(char *name_dir)
{
	size_t	len;

	len = 0;
	len = ft_strlen(name_dir);
	if (name_dir[len - 1] == '.' && name_dir[len - 2] == '/')
		return (1);
	if (name_dir[len - 1] == '.' && name_dir[len - 2] == '.')
		return (1);
	return (0);
}

/*
** Собирает статистику по каждому файлу, если поднят флаг l.
*/

void	ft_stat(char **arr, t_flag *fl, void (*fcn)(char *, t_flag *))
{
	struct stat	stbuf;
	int			i;

	i = -1;
	while (arr[++i] != NULL)
	{
		if (lstat(arr[i], &stbuf) == -1)
			ft_printf("Not access to file  %s\n", arr[i]);
		//ft_printf("uid_y = %d\n", stbuf.st_atime); 
		if (ft_chack_parent_dir(arr[i]))
			continue ;
		//ft_printf("!!!!stbuf.st_mode %d\n", stbuf.st_mode);
		if (S_ISDIR(stbuf.st_mode))
			fcn(arr[i], fl);
	}
}

/*
** Функция для печати только последней директории. 
*/

void	*ft_last_ndir(char *dir)
{
	size_t	len;

	len = ft_strlen(dir);
	while (--len >= 0)
		if (dir[len] == '/' || len == 0)
		{
			if (dir[len] == '.' || dir[len] == '/')
				return (&dir[len + 1]);
			else
				return (&dir[len]);
		}

	return (NULL);
}

/*
** Функция обрабатывает файлы пречисленные в командной строке
** для функции ft_flag_handing.c. 
*/

int		ft_flag_handing_reg(t_flag *fl, int ac, char **av)
{
	struct	stat	st_buf;
	int				i;
	char			**arr_n;
	char			*str_n;

	str_n = ft_strnew(0);
	arr_n = NULL;
	i = 1;
	while (--ac - 1 > 0)
	{
		if (lstat(*(++av + 1), &st_buf) == -1)
		{
			ft_printf("ft_ls: %s: No such file or directory\n", *(av + 1));
			continue ;
		}
		if (!S_ISDIR(st_buf.st_mode))
		{
			str_n = ft_strnjoinfree(str_n, *(av + 1));
			str_n = ft_strnjoinfree(str_n, "|");
		}
	}
	if (*str_n == '\0')		
	{
		free(str_n);
		return (0);
	}
	arr_n = ft_strsplit(str_n, '|');
	ft_sort_arr(&arr_n, fl);
	if (fl->flag_l)
		ft_flag_l(arr_n, fl);
	else
		ft_indent(arr_n);
	free(str_n);
	ft_del_arr(arr_n);
	return (1);
}

/*
** Функция обрабатывает файлы пречисленные в командной строке
** для функции ft_flag_handing.c. 
*/

void	ft_flag_handing_dir(t_flag *fl, int ac, char **av, int bl)
{
	struct	stat	st_buf;
	char			**arr_d;
	char			*str_d;
	int				i;

	i = 1;
	str_d = ft_strnew(0);
	while (--ac - 1 > 0)
	{
		if (lstat(*(++av + 1), &st_buf) == -1)
			continue ;
		if (S_ISDIR(st_buf.st_mode))
		{
			str_d = ft_strnjoinfree(str_d, *(av + 1));
			str_d = ft_strnjoinfree(str_d, "|");
		}
	}
	if (*str_d == '\0')		
	{
		free(str_d);
		return ;
	}
	arr_d = ft_strsplit(str_d, '|');
	ft_sort_arr(&arr_d, fl);
	while (*arr_d != NULL)
	{
		if (i > 0 && bl)
			ft_printf("\n%s:\n", *arr_d);
		ft_open_dir(*arr_d, fl);
		i = 0;
		arr_d++;
	}
	ft_del_arr(arr_d);
	free(str_d);
}
