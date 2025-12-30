CC = clang
EXEC = lib/my/libmy.a
SRC = lib/my/my_putstr.c lib/my/my_putchar.c lib/my/my_put_nbr.c lib/my/my_strlen.c lib/my/my_strcpy.c lib/my/my_atoi.c lib/my/error_handling_args.c lib/my/my_strcomp.c lib/my/ascii_comp.c lib/my/sort_by_name.c lib/my/sort_by_id.c lib/my/sort_by_type.c
OBJ = lib/my/my_putstr.o lib/my/my_putchar.o lib/my/my_put_nbr.o lib/my/my_strlen.o lib/my/my_strcpy.o lib/my/my_atoi.o lib/my/error_handling_args.o lib/my/my_strcomp.o lib/my/ascii_comp.o lib/my/sort_by_name.o lib/my/sort_by_id.o lib/my/sort_by_type.o
# CFLAGS = -Wall -Wextra -Werror -Iinclude

all : $(EXEC)

*.o : *.c 
	$(CC) $(CFLAGS)

$(EXEC) : $(OBJ)
	ar rc $(EXEC) $(OBJ)
	clang -o organized main.c add.c sort.c disp.c del.c -L ./lib/my -lmy -lshell -Iinclude -g3

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(EXEC)

re : fclean clean all
