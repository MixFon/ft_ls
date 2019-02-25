#include "ft_ls.h"
#include <sys/types.h>
#include <dirent.h>

void	ft_open_dir(char *name_dir)
{
	DIR				*dir;
	struct dirent	*dirent;

	if (!(dir = opendir(name_dir)))
	{
		ft_printf("No open %s", name_dir);
		return ;
	}
	while ((dirent = readdir(dir)) != NULL)
		ft_printf("%s\n", dirent->d_name);
	closedir(dir);
}


int main (int ac, char **av)
{
	int i;

	i = 1;
	if (ac == 1)
		ft_open_dir(".");
	else 
		while (i < ac)
		{
			ft_open_dir(av[i]);
			i++;
		}
	return (0);
}
