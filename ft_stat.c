
#include "ft_ls.h"

void	ft_stat(char **arr, t_flag *fl, void (*fcn)(char *, t_flag *))
{
	struct stat	stbuf;
	int			i;

	i = -1;
	while (arr[++i] != NULL)
	{
		if (stat(arr[i], &stbuf) == -1)
			ft_printf("Not access to file  %s\n", arr[i]);
		//return;
		if (ft_strcmp(arr[i], ".") == 0 || ft_strcmp(arr[i], "..") == 0)
			continue ;
		if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
			fcn(arr[i], fl);
	}
}
