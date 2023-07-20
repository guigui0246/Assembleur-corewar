##
## EPITECH PROJECT, 2023
## corewar
## File description:
## Makefile
##

CC ?= gcc

CFLAGS += -Wall -Wextra

INCLUDE_DIR +=

CPPFLAGS += $(foreach inc, $(INCLUDE_DIR), -iquote$(inc))

LIB +=

LIB_DIR +=

LIB_TO_MAKE +=

LDFLAGS += $(foreach lib, $(LIB_DIR), -L$(lib))
LDLIBS += $(foreach lib, $(LIB), -l$(lib))

TEST_DIR = ./tests

TESTFLAGS += --coverage -lcriterion

TESTFILES =

TESTS += $(foreach test, $(TESTFILES), $(TEST_DIR)/$(TESTFILES))

NAME_ASM = asm/asm

NAME_VM = corewar/corewar

all: $(NAME_ASM) $(NAME_VM)

make_lib:
	$(foreach lib, $(LIB_TO_MAKE), make -i -C $(lib);)

$(NAME_ASM): make_lib
	make -C asm

$(NAME_VM): make_lib
	make -C corewar

clean:
	$(foreach lib, $(LIB_TO_MAKE), make clean -i -C $(lib);)
	make -i -C asm clean
	make -i -C corewar clean

fclean: clean
	$(foreach lib, $(LIB_TO_MAKE), make fclean -i -C $(lib);)
	make -i -C asm fclean
	make -i -C corewar fclean

$(TEST_NAME_ASM): re
	$(CC) -o $(TEST_NAME_ASM) $(TESTS) $(OBJ) $(OBJ_ASM) $(CFLAGS) \
	$(LDFLAGS) $(LDLIBS) $(TESTFLAGS)

tests_run:
	make -C corewar tests_run
	make -C asm tests_run

re: fclean all

.PHONY	: clean fclean re all make_lib
