##
## EPITECH PROJECT, 2023
## corewar
## File description:
## Makefile asm
##

CC ?= gcc

SRC = ../op.c\
		add_ptr_to_array.c\
		main.c\
		ernno.c\
		fclose.c\
		fill_line.c\
		label_format.c\
		format.c\
		malloc.c\
		my_strlen_until.c\
		my_strlen.c\
		my_strnbr_base.c\
		random.c\
		write_command.c\
		my_array_len.c\
		my_strcpy.c\
		my_strncmp.c\
		rm_2d_array.c\
		my_getnbr.c\
		find_op_tab_line.c\
		op_t_is_null.c\
		write_info.c\
		my_strdup.c\
		my_strndup.c\
		my_strcmp.c\
		file_info_t_errors.c\
		ptr_is_all_empty.c\
		my_strncpy.c\
		my_strcpy_until.c\
		write_second_command.c

OBJ = $(SRC:.c=.o)

CFLAGS += -Wall -Wextra

INCLUDE_DIR += ../includes\
				includes

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

NAME = asm

TEST_NAME = $(NAME)-unit-test

all: $(NAME)

make_lib:
	$(foreach lib, $(LIB_TO_MAKE), make -i -C $(lib);)

$(NAME): make_lib $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

clean:
	$(foreach lib, $(LIB_TO_MAKE), make clean -i -C $(lib);)
	rm -f $(OBJ)

fclean: clean
	$(foreach lib, $(LIB_TO_MAKE), make fclean -i -C $(lib);)
	rm -f $(NAME)

$(TEST_NAME): re
	$(CC) -o $(TEST_NAME) $(TESTS) $(OBJ) $(OBJ) $(CFLAGS) \
	$(LDFLAGS) $(LDLIBS) $(TESTFLAGS)

tests_run: $(TEST_NAME)
	./$(TEST_NAME)
	gcovr $(foreach test, $(TESTS), --exclude $(test))
	gcovr $(foreach test, $(TESTS), --exclude $(test)) -b

re: fclean all

.PHONY	: clean fclean re all make_lib
