
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

void	ft_stat(char **arr, t_flag *fl, void (*fcn)(char *, t_flag *))
{
	struct stat	stbuf;
	int			i;

	i = -1;
	while (arr[++i] != NULL)
	{
		if (stat(arr[i], &stbuf) == -1)
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
			return (&dir[len + 1]);
	return (NULL);
}
