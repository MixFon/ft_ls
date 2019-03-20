
#include "ft_ls.h"

t_filds	*ft_create_fild(void)
{
	t_filds	*new;

	if(!(new = (t_filds *)malloc(sizeof(t_filds))))
		return (NULL);
	new->rights = NULL;
	new->links = 0;
	new->users = NULL;
	new->grups = NULL;
	new->size = 0;
	new->mon = NULL;
	new->day = NULL;
	new->time = NULL;
	new->name = NULL;
	new->next = NULL;
	new->major = 0;
	new->minor = 0;
	new->xattr = NULL;
	new->acl = NULL;
	return (new);
}

/*
** Функиция определяет количество символов для выравнимания.
*/

size_t	ft_num(int arg)
{
	int filds;

	filds = 0;
	while (arg != 0)
	{
		arg = arg / 10;
		filds++;
	}
	return (filds);
}

/*
** Функиция заполняет отступы для выравнивания.
*/

void	ft_paragraph(t_filds *fild, t_fsize *fs)
{
	int	temp;

	temp = 0;
	while (fild != NULL)
	{
		temp = ft_num(fild->links);
		if (temp > fs->ln)
			fs->ln = temp;
		temp = ft_strlen(fild->users);
		if (temp >= fs->us)
			fs->us = temp + 2;
		temp = ft_strlen(fild->grups);
		if (temp > fs->gr)
			fs->gr = temp + 2;
		temp = ft_num(fild->size);
		if (temp > fs->sz)
			fs->sz = temp;
		temp = ft_num(fild->major);
		if (temp > fs->sma)
			fs->sma = temp + 2;
		temp = ft_num(fild->minor);
		if (temp > fs->smi)
			fs->smi = temp + 1;
		fild = fild->next;
	}
	//ft_printf("%d %d %d %d\n", *ln, *us, *gr, *sz);
}	

void	ft_print_filds(t_filds *fild, t_flag *fl)
{
	t_fsize	*fs;

	fs = ft_new_fsize();
	ft_paragraph(fild, fs);
	while (fild != NULL)
	{
		if (fild->major == 0 && fild->major == 0)
			ft_printf("%-11s %*d %-*s%-*s%*zd %s %2s %5s %s\n",
		fild->rights, fs->ln, fild->links, fs->us, fild->users,
		fs->gr, fild->grups, fs->sz + fs->sma + fs->smi, fild->size, fild->mon, fild->day,
		fild->time, fild->name);
		else
			ft_printf("%-11s %*d %-*s%-*s%*d,%*d %s %2s %5s %s\n",
		fild->rights, fs->ln, fild->links, fs->us, fild->users,
		fs->gr, fild->grups, fs->sma - 1, fild->major, fs->smi, fild->minor, 
		fild->mon, fild->day,
		fild->time, fild->name);
		if (fl->flag_dog && fild->xattr)
			ft_printf("%26s%10s\n", fild->xattr, "0");
		if (fl->flag_e && fild->acl)
			ft_printf("%s", ft_strchr(fild->acl, '\n') + 1);
		fild = fild->next;
	}
	ft_del_fsize(fs);
}

/*
** Функиция заполняющая строку времени в выводе даты.
*/

void	ft_del_filds(t_filds *fild)
{
	t_filds	*prev;

	prev = NULL;
	while (fild != NULL)
	{
		free(fild->rights);
		free(fild->users);
		free(fild->grups);
		free(fild->mon);
		free(fild->day);
		free(fild->time);
		free(fild->name);
		free(fild->acl);
		free(fild->xattr);
		prev = fild;
		fild = fild->next;
		free(prev);
		prev = NULL;
	}
	fild = NULL;
}
