
#include "../ft_ls/libft_last_ver/libft.h"
#include "../ft_ls/libft_last_ver/ft_printf.h"

char	*ft_multi_strdup(int count, ...)
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
	while(count > 0)
	{
		ptr = va_arg(list_arg, const char*);
		str = ft_strncat(str, ptr, ft_strlen(ptr));
		count--;
	}	
	va_end(list_arg);
	return (str);
}

int	main()
{
	char *a = "1234";
	char *b = "1234";
	char	*len;

	len = 0;
	len = ft_multi_strdup(4, a, b, "Hello", "World");
	ft_printf("len = %s", len);
	free(len);
	return (0);
}
