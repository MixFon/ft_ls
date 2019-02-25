#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main (int ac, char **av)
{
	DIR				*dir;
	struct dirent	*dirent;

	dir = opendir("/");
	while ((dirent = readdir(dir)) != NULL)
		printf("%s\n", dirent->d_name);
	closedir(dir);
	return (0);
}
