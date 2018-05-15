NAMEVM = corewar
NAMEASM = asm

CC = gcc

SRCVM = src/vm/vm.c src/vm/load_argv.c src/vm/load_champ.c \
	src/vm/initialize_battlefield.c \
	src/vm/process_loop.c src/vm/process_stack.c src/vm/mem_cp_endianness.c \
	src/vm/load_instruction.c src/vm/print_memory.c src/vm/init_print.c \
	src/vm/iprint.c src/vm/print_tools.c src/vm/print_champ_info.c

SRCASM = src/asm/asm.c src/asm/label.c src/asm/transitions.c src/asm/asm_loop.c\
	src/asm/tools.c

FLAGS = -Wall -Werror -Wextra -Winline -Wredundant-decls -Wno-padded -Wno-gnu-binary-literal
#FLAGS = -Weverything -Wall -Werror -Wextra -Winline -Wredundant-decls -Wno-padded -Wno-gnu-binary-literal

OBJVM = $(SRCVM:.c=.o)
OBJASM = $(SRCASM:.c=.o)

all : $(NAMEVM) $(NAMEASM)

$(NAMEVM): $(OBJVM)
	$(CC) $(FLAGS) $(OBJVM) $(LIBS) -o $(NAMEVM)

$(NAMEASM): $(OBJASM)
	$(CC) $(FLAGS) $(OBJASM) $(LIBS) -o $(NAMEASM)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean :
	rm -f $(OBJVM)
	rm -f $(OBJASM)

fclean : clean
	rm -f $(NAMEVM)
	rm -f $(NAMEASM)

re : fclean all
