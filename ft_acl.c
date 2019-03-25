/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_acl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 11:40:41 by widraugr          #+#    #+#             */
/*   Updated: 2019/03/25 15:39:09 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_bl(char *name_dir)
{
	static int		bl = 0;

	if (bl)
		ft_printf("\n%s:\n", name_dir);
	bl = 1;
	return (NULL);
}

void	ft_del_arr_dir(char **arr, DIR **dir, char **str)
{
	ft_del_arr(arr);
	free(arr);
	free(*str);
	closedir(*dir);
}

char	**ft_sort_print_arr(char *str, t_flag *fl)
{
	char	**arr;

	arr = ft_strsplit(str, '|');
	ft_sort_arr(&arr, fl);
	ft_print_arr(arr, fl);
	return (arr);
}

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
