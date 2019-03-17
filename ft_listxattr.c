
#include "ft_ls.h"

void	ft_acl(char *rights, char *path)
{
	char	*list;
	int		len;
	acl_t	acl;

	list = ft_strnew(1000);
	len = listxattr(path, list, 1000, XATTR_NOFOLLOW);
	acl = acl_get_file(path, ACL_TYPE_EXTENDED);
	if (acl != NULL)
		rights[10] = '+';
	if (len > 0)
		rights[10] = '@';
	free(list);
}
