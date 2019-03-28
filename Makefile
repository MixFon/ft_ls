# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: widraugr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 10:31:41 by widraugr          #+#    #+#              #
#    Updated: 2019/03/25 16:44:59 by widraugr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

LIB_FILE = libft.a

CFILES =  main.c\
ft_access_rights.c\
ft_acl.c\
ft_filds.c\
ft_flag_handing.c\
ft_flag_l.c\
ft_indent.c\
ft_list_flag.c\
ft_new_fsize.c\
ft_stat.c\
ft_lstat_iter.c\
ft_sort_time.c

OFILES = main.o\
ft_access_rights.o\
ft_acl.o\
ft_filds.o\
ft_flag_handing.o\
ft_flag_l.o\
ft_indent.o\
ft_list_flag.o\
ft_new_fsize.o\
ft_stat.o\
ft_lstat_iter.o\
ft_sort_time.o

FLAGS = -Wall -Wextra -Werror

HFILE = -I.

all: $(NAME)

$(NAME):
	make re -C ./libft_last_ver
	gcc -g $(FLAGS) $(HFILES) -c $(CFILES) 
	gcc -g $(FLAFS) $(OFILES) -L./libft_last_ver -lftprintf -o $(NAME)

clean: 
	/bin/rm -f $(OFILES)
	make clean -C ./libft_last_ver 

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C ./libft_last_ver 

re: fclean all
