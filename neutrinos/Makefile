CC = clang
EXEC = lib/my/libmy.a
SRC = lib/my/my_putstr.c lib/my/my_putchar.c lib/my/my_put_nbr.c  
OBJ = lib/my/my_putstr.o lib/my/my_putchar.o lib/my/my_put_nbr.o
CFLAGS = -Wall -Wextra -Werror -Iinclude -g3

all : $(EXEC)

*.o : *.c 
	$(CC) $(CFLAGS)

$(EXEC) : $(OBJ)
	ar rc $(EXEC) $(OBJ)
	clang -o 104neutrinos main.c -L ./lib/my/ -lmy -lm -g3

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(EXEC)

re : fclean clean all
