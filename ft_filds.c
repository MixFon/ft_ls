
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

void	ft_paragraph(t_filds *fild, int *ln, int *us, int *gr, int *sz)
{
	int	temp;

	temp = 0;
	while (fild != NULL)
	{
		temp = ft_num(fild->links);
		if (temp > *ln)
			*ln = temp;
		temp = ft_strlen(fild->users);
		if (temp > *us)
			*us = temp + 1;
		temp = ft_strlen(fild->grups);
		if (temp > *gr)
			*gr = temp + 1;
		temp = ft_num(fild->size);
		if (temp > *sz)
			*sz = temp;
		fild = fild->next;
	}
	//ft_printf("%d %d %d %*d", *ln, *us, *gr, *sz);
}	

void	ft_print_filds(t_filds *fild)
{
	int	ln;
	int	us;
	int	gr;
	int	sz;

	ln = 0;
	us = 0;
	gr = 0;
	sz = 0;
	ft_paragraph(fild , &ln, &us, &gr, &sz);
	while (fild != NULL)
	{
		printf("%s  %*d %-*s %-*s %*zd %s %2s %s %s\n",
		fild->rights, ln, fild->links, us, fild->users,
		 gr, fild->grups, sz, fild->size, fild->mon, fild->day,
		fild->time, fild->name);
		fild = fild->next;
	}

}

/*
** Функиция заполняющая строку времени в выводе даты.
*/

void	ft_del_filsa(t_filds *fild)
{
	t_filds	*prev;

	prev = NULL;
	while (fild->next != NULL)
	{
		free(fild->rights);
		free(fild->users);
		free(fild->grups);
		free(fild->mon);
		free(fild->day);
		free(fild->time);
		free(fild->name);
		prev = fild;
		fild = fild->next;
		free(prev);
		prev = NULL;
	}
	free(fild);
	fild = NULL;
}
