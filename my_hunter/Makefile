CC = clang
EXEC = lib/my/libmy.a
SRC = lib/my/my_putchar.c lib/my/my_putstr.c lib/my/game_screen.c lib/my/sprite_game.c lib/my/display.c lib/my/deplacement.c lib/my/set_pos.c lib/my/display_hb.c lib/my/game_over.c lib/my/flagh.c
OBJ = lib/my/my_putchar.o lib/my/my_putstr.o lib/my/game_screen.o lib/my/sprite_game.o lib/my/display.o lib/my/deplacement.o lib/my/set_pos.o lib/my/display_hb.o lib/my/game_over.o lib/my/flagh.o
# CFLAGS = -Wall -Wextra -Werror -Iinclude -g3 

all : $(EXEC)

*.o : *.c 
	$(CC) $(CFLAGS)

$(EXEC) : $(OBJ)
	ar rc $(EXEC) $(OBJ)
	clang -o my_hunter my_hunter.c -L ./lib/my/ -lmy -lcsfml-graphics -lcsfml-system -lcsfml-window -g3

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(EXEC)


re : fclean clean all
