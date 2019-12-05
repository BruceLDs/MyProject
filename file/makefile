SRC =  $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
BIN = out


$(BIN):$(OBJ)
	gcc $^ -o $@

%.o:%.c
	gcc -c $< -o $@
clean:
	rm $(BIN) $(OBJ)
