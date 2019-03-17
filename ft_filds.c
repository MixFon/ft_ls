
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

void	ft_paragraph(t_filds *fild, int *ln, int *us, int *gr, int *sz, int *sma, int *smi)
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
			*gr = temp + 2;
		temp = ft_num(fild->size);
		if (temp > *sz)
			*sz = temp;
		temp = ft_num(fild->major);
		if (temp > *sma)
			*sma = temp;
		temp = ft_num(fild->minor);
		if (temp > *smi)
			*smi = temp;
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
	int	sma;
	int	smi;

	ln = 0;
	us = 0;
	gr = 0;
	sz = 0;
	sma = 0;
	smi = 0;
	ft_paragraph(fild , &ln, &us, &gr, &sz, &sma, &smi);
	while (fild != NULL)
	{
		if (fild->major == 0 && fild->major == 0)
			ft_printf("%-11s %*d %-*s %-*s %*zd %s %2s %5s %s\n",
		fild->rights, ln, fild->links, us, fild->users,
		gr, fild->grups, sz + sma + smi + 2, fild->size,  fild->mon, fild->day,
		fild->time, fild->name);
		else
			ft_printf("%-11s %*d %-*s %-*s %*d, %*d %s %2s %5s %s\n",
		fild->rights, ln, fild->links, us, fild->users,
		gr, fild->grups, sma, fild->major, smi, fild->minor, 
		fild->mon, fild->day,
		fild->time, fild->name);
		fild = fild->next;
	}
}

/*
** Функиция заполняющая строку времени в выводе даты.
*/

void	ft_del_filds(t_filds *fild)
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
