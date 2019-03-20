
#include "ft_printf.h"

char			*ft_multi_strdup(int count, ...)
{
	va_list		list_arg;
	int			i;
	size_t		len;
	char		*str;
	const char	*ptr;

	i = -1;
	len = 0;
	va_start(list_arg, count);
	while(++i < count)
		len += ft_strlen(va_arg(list_arg, const char *));
	va_end(list_arg);
	if(!(str = ft_strnew(len)))
		return (NULL);
	va_start(list_arg, count);
	i = -1;
	while(++i < count)
	{
		ptr = va_arg(list_arg, const char*);
		if (ptr == NULL)
			continue ;
		str = ft_strncat(str, ptr, ft_strlen(ptr));
	}	
	va_end(list_arg);
	return (str);
}
