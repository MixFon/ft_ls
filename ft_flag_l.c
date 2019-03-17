

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
	ft_printf("S_IRWXU\t\t %d\n", S_IRWXU);
	ft_printf("Mask \t\t %d\n", (st_buf->st_mode & S_IXUSR));
	ft_printf("S_IRUSR\t\t %d\n", S_IRUSR);
	ft_printf("S_IWUSR\t\t %d\n", S_IWUSR);
	ft_printf("S_IXUSR\t\t %d\n", S_IXUSR);
	ft_printf("S_ISVTX\t\t %d\n", S_ISVTX);

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

/*
** Печатает стрку total.
*/

void	ft_print_total(char **arr)
{
	struct stat		*st_buf;
	size_t			total;

	total = 0;
	while (*arr)
	{
		st_buf = (struct stat *)malloc(sizeof(struct stat));
		if (lstat(*arr, st_buf) < 0)
		{
			//ft_printf("Error lstat");
			arr++;
			continue ;
		}
		if ((st_buf->st_mode & S_IFMT) != S_IFLNK)
			total += st_buf->st_blocks;
		free(st_buf);
		arr++;
	}
	ft_printf("total %d\n", total);
}

/*
** Создает строку содержащую время.
*/

char	*ft_infill_dt_time(char *time)
{
	char *str_time;

	str_time = ft_strnew(5);
	if (ft_strcl(time, '\n') == 4)
		ft_strncpy(str_time, time, 4);
	else
		ft_strncpy(str_time, time, 5);
	return (str_time);
}

/*
** Обрабатывает дату.
*/

void	ft_work_date(t_filds *fild, struct stat *st_buf)
{
	struct tm		*tm_buf;
	char			**date;
	long long int	real_sec;

	fild->major = major(st_buf->st_rdev);
	fild->minor = minor(st_buf->st_rdev);
	//ft_printf("major %d ", major(st_buf->st_rdev));
	//ft_printf("minor %d\n", minor(st_buf->st_rdev));
	date = ft_strsplit(ctime(&st_buf->st_mtime), ' '); 
	real_sec = time(NULL);
	fild->mon = ft_strdup(date[1]);
	fild->day = ft_strdup(date[2]);
	if ((real_sec - st_buf->st_mtime) > 15638400)
		fild->time = ft_infill_dt_time(date[4]);
	else
		fild->time = ft_infill_dt_time(date[3]);
	ft_del_arr(date);
}


/*
** Создает новый элемент списка filds и добавляет уго в конец.
*/

t_filds	*ft_stat_line(struct stat *st_buf, char *path,
		struct passwd *pas_buf, t_filds *first_fild)
{
	struct group	*gr_buf;
	t_filds			*fild;
	t_filds			*first;

	first = first_fild;
	fild = ft_create_fild();
	gr_buf = getgrgid(st_buf->st_gid);
	ft_create_rights(fild, st_buf, path);
	fild->links = st_buf->st_nlink;
	fild->users = ft_strdup(pas_buf->pw_name);
	fild->grups = ft_strdup(gr_buf->gr_name);
	fild->size = st_buf->st_size;
	ft_work_date(fild, st_buf);
	ft_link_name(st_buf, path);
	fild->name = ft_link_name(st_buf, path);
	if (first_fild == NULL)
		first = fild;
	else
	{
		while (first_fild->next != NULL)
			first_fild = first_fild->next;
		first_fild->next = fild;
	}
	return (first);
}

/*
** При поднятом флаге l создает список из файлов
*/

void	ft_flag_l(char **arr, t_flag *fl)
{
	struct passwd	*pas_buf;
	struct stat		*st_buf;
	t_filds			*filds;

	filds = NULL;
	while (*arr != NULL)
	{
		st_buf = (struct stat *)malloc(sizeof(struct stat));
		if (lstat(*arr, st_buf) < 0)
		{
			arr++;
			continue ;
		}
		pas_buf = getpwuid(st_buf->st_uid);
		filds = ft_stat_line(st_buf, *arr, pas_buf, filds);
		free(st_buf);
		arr++;
	}
	ft_print_filds(filds);
	ft_del_filds(filds);
}
/*
void	ft_stat_line(struct stat *st_buf, char *name,
		struct passwd *pas_buf, t_filds *fild)
{
	char			*rights;
	struct group	*gr_buf;
	struct tm		*tm_buf;
	char			**date;
	char			*dt_time;

	if (fild == NULL)
		fild = ft_create_fild();
	while (fild->next != NULL)
		fild = fild->next;
	gr_buf = getgrgid(st_buf->st_gid);
	rights = ft_strnew(10);
	tm_buf = gmtime(&st_buf->st_ctime);
	//ft_printf("char time %s", ctime(&st_buf->st_ctime));
	//ft_printf("asctime  %d\n",asctime(tm_buf));
	//ft_printf("hour %d min %d\n", tm_buf->tm_hour, tm_buf->tm_min);
	date = ft_strsplit(ctime(&st_buf->st_ctime), ' '); 
	dt_time = ft_infill_dt_time(date[3]);
	//ft_printf("filds %d\n", ft_num(3994));
	ft_type_files(rights, st_buf);
	ft_access_rights_user(rights, st_buf);
	ft_access_rights_grup(rights, st_buf);
	ft_access_rights_all(rights, st_buf);
	//ft_printf("rights '%s'\n", rights);
	ft_printf("%s %2d %s %s %5d %s %s %s %s\n",
			rights, st_buf->st_nlink, pas_buf->pw_name,
			gr_buf->gr_name, st_buf->st_size, date[1], date[2], dt_time, name);
	ft_del_arr(date);
	free(dt_time);
	free(rights);
}
*/
