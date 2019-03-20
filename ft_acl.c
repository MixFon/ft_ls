
#include "ft_ls.h"

void	ft_acl(t_filds *fild, char *path)
{
	char	*list;
	ssize_t	ssize;
	int		len;
	acl_t	acl;

	ssize = 1000;
	list = ft_strnew(1000);
	len = listxattr(path, list, 1000, XATTR_NOFOLLOW);
	acl = acl_get_file(path, ACL_TYPE_EXTENDED);
	if (acl != NULL)
	{
		fild->rights[10] = '+';
		fild->acl = ft_strdup(acl_to_text(acl, &ssize));
	}
	if (len > 0)
	{
		fild->rights[10] = '@';
		fild->xattr = ft_strdup(list);
	}
	//ft_printf("list%s\n", fild->xattr);
	free(list);
}

/*
** Усли указан флаг l в символьной ссылке в имени указывается
** файл, на который ссылается ссылка.
*/

char	*ft_link_name(struct stat *st_buf, char *path)
{
	char	*name;
	char	*buf;

	buf = ft_strnew(100);
	if (S_ISLNK(st_buf->st_mode))
	{
		readlink(path, buf, 100);
		name = ft_strdup(ft_last_ndir(path));
		name = ft_strnjoinfree(name, " -> ");
		name = ft_strnjoinfree(name, buf);
	}
	else
		name = ft_strdup(ft_last_ndir(path));
	return (name);
}
