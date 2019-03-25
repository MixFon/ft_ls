/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_acl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 11:40:41 by widraugr          #+#    #+#             */
/*   Updated: 2019/03/21 16:14:48 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_acl(t_filds *fild, char *path)
{
	char	*list;
	ssize_t	ssize;
	int		len;
	acl_t	acl;

	list = ft_strnew(1000);
	len = listxattr(path, list, 1000, XATTR_NOFOLLOW);
	acl = acl_get_file(path, ACL_TYPE_EXTENDED);
	if (acl != NULL)
	{
		fild->rights[10] = '+';
		fild->acl = acl_to_text(acl, &ssize);
	}
	if (len > 0)
	{
		fild->rights[10] = '@';
		fild->xattr = ft_strdup(list);
	}
	free(acl);
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
		name = ft_multi_strdup(3, ft_last_ndir(path), " -> ", buf);
	}
	else
		name = ft_strdup(ft_last_ndir(path));
	free(buf);
	return (name);
}
