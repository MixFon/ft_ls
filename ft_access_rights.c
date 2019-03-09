
#include "ft_ls.h"


void	ft_type_files(char *rights, struct stat *st_buf)
{
	if (S_ISDIR(st_buf->st_mode))
		*rights = 'd';
	else	if (S_ISLNK(st_buf->st_mode))
		*rights = 'l';
	else	if (S_ISREG(st_buf->st_mode))
		*rights = '-';
	else	if (S_ISBLK(st_buf->st_mode))
		*rights = 'b';
	else	if (S_ISCHR(st_buf->st_mode))
		*rights = 'c';
	else	if (S_ISFIFO(st_buf->st_mode))
		*rights = 'p';
	else	if (S_ISSOCK(st_buf->st_mode))
		*rights = 's';
}

void	ft_access_rights_user(char *rights, struct stat *st_buf)
{
	if ((st_buf->st_mode & S_IRUSR) == S_IRUSR)
		*(rights + 1) = 'r';
	else
		*(rights + 1) = '-';
	if ((st_buf->st_mode & S_IWUSR) == S_IWUSR)
		*(rights + 2) = 'w';
	else
		*(rights + 2) = '-';
	if ((st_buf->st_mode & S_IXUSR) == S_IXUSR)
		*(rights + 3) = 'x';
	else
		*(rights + 3) = '-';
}

void	ft_access_rights_grup(char *rights, struct stat *st_buf)
{
	if ((st_buf->st_mode & S_IRGRP) == S_IRGRP)
		*(rights + 4) = 'r';
	else
		*(rights + 4) = '-';
	if ((st_buf->st_mode & S_IWGRP) == S_IWGRP)
		*(rights + 5) = 'w';
	else
		*(rights + 5) = '-';
	if ((st_buf->st_mode & S_IXGRP) == S_IXGRP)
		*(rights + 6) = 'x';
	else
		*(rights + 6) = '-';
}

void	ft_access_rights_all(char *rights, struct stat *st_buf)
{
	if ((st_buf->st_mode & S_IROTH) == S_IROTH)
		*(rights + 7) = 'r';
	else
		*(rights + 7) = '-';
	if ((st_buf->st_mode & S_IWOTH) == S_IWOTH)
		*(rights + 8) = 'w';
	else
		*(rights + 8) = '-';
	if ((st_buf->st_mode & S_IXOTH) == S_IXOTH)
		*(rights + 9) = 'x';
	else
		*(rights + 9) = '-';

}

void	ft_create_rights(t_filds *fild, struct stat *st_buf)
{
	fild->rights = ft_strnew(10);
	ft_type_files(fild->rights, st_buf);
	ft_access_rights_user(fild->rights, st_buf);
	ft_access_rights_grup(fild->rights, st_buf);
	ft_access_rights_all(fild->rights, st_buf);
}
