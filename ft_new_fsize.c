/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_fsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 10:58:01 by widraugr          #+#    #+#             */
/*   Updated: 2019/03/25 11:18:40 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_fsize	*ft_new_fsize(void)
{
	t_fsize *new_fs;

	if (!(new_fs = (t_fsize *)malloc(sizeof(t_fsize))))
		return (NULL);
	new_fs->ln = 0;
	new_fs->us = 0;
	new_fs->gr = 0;
	new_fs->sz = 0;
	new_fs->sma = 0;
	new_fs->smi = 0;
	return (new_fs);
}

void	ft_del_fsize(t_fsize *fs)
{
	fs->ln = 0;
	fs->us = 0;
	fs->gr = 0;
	fs->sz = 0;
	fs->sma = 0;
	fs->smi = 0;
	free(fs);
}
