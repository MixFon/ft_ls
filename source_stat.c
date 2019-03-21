
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
