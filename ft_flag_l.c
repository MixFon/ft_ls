
#include "ft_ls.h"

void	ft_pitnt_stat(char *name, struct stat *st_buf)
{
	ft_printf("\nStat:\narr %s\n", name);
	ft_printf("st_dev\t\t %d\n", st_buf->st_dev);
	ft_printf("st_ino\t\t %d\n", st_buf->st_ino);
	ft_printf("st_mode\t\t %d\n", (st_buf->st_mode & S_IFMT));
	ft_printf("st_nlink\t %d\n", st_buf->st_nlink);
	ft_printf("st_uid\t\t %d\n", st_buf->st_uid);
	ft_printf("st_gid\t\t %d\n", st_buf->st_gid);
	ft_printf("st_rdev\t\t %d\n", st_buf->st_rdev);
	ft_printf("st_size\t\t %d\n", st_buf->st_size);
	ft_printf("st_blksize\t %d\n", st_buf->st_blksize);
	ft_printf("st_blocks\t %d\n", st_buf->st_blocks);
	ft_printf("st_atime\t %d\n", st_buf->st_atime);
	ft_printf("st_mtime\t %d\n", st_buf->st_mtime);
	ft_printf("st_ctime\t %d\n", st_buf->st_ctime);
	ft_printf("S_IFDIR\t\t %d\n", S_IFDIR);

}

void	ft_print_passwd(struct passwd *pas_buf)
{
	ft_printf("\nPasswd:\npw_name\t\t %s\n", pas_buf->pw_name);
	ft_printf("pw_passwd\t %s\n", pas_buf->pw_passwd);
	ft_printf("pw_uid\t\t %d\n", pas_buf->pw_uid);
	ft_printf("pw_gid\t\t %d\n", pas_buf->pw_gid);
	ft_printf("pw_gecos\t %s\n", pas_buf->pw_gecos);
	ft_printf("pw_dir\t\t %s\n", pas_buf->pw_dir);
	ft_printf("pw_shell\t %s\n", pas_buf->pw_shell);
}

char	*ft_access_rights(char *rights, struct stat *st_buf)
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
	return (rights);
}

void	ft_stat_line(struct stat *st_buf)
{
	char *rights;

	rights = ft_strnew(10);
	ft_access_rights(rights, st_buf);
	ft_printf("rights '%s'\n", rights);
}

void	ft_flag_l(char **arr, t_flag *fl)
{
	struct passwd	*pas_buf;
	struct stat		*st_buf;

//	ft_printf("Here is flag l'%s'\n", *arr);
	arr++;
	st_buf = (struct stat *)malloc(sizeof(struct stat));
	stat(*arr, st_buf);
	ft_stat_line(st_buf);
	ft_pitnt_stat(*arr, st_buf);
	free(st_buf);
	pas_buf = getpwuid(st_buf->st_uid);
	ft_print_passwd(pas_buf);
}
