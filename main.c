#include "ft_ls.h"
#include <sys/types.h>
#include <dirent.h>

void	ft_open_dir(char *name_dir)
{
	DIR				*dir;
	struct dirent	*dirent;


	if (!(dir = opendir(name_dir)))
	{
		printf("No open %s\n", name_dir);
		return ;
	}
	while ((dirent = readdir(dir)) != NULL)
		ft_printf("%s\n", dirent->d_name);
	closedir(dir);
}


/*
** Функция считывания флагов.
*/

t_flag	*ft_readflag(char *flag)
{
	t_flag *new_fl;

	if new_fl = (t_flag *)malloc(sizeof(t_flag));

	ft_printf("%s\n", flag);
	return (new_fl);
}


int main (int ac, char **av)
{
	t_flag	*fl;

	fl = ft_readflag(av[1]);
	free(fl);
	return (0);
}
