NAME = pathfinder

SRC =  mx_count_parallel \
		mx_create_node_custom \
		mx_deixtra \
		mx_deixtra_cycle \
		mx_is_done \
		mx_is_min \
		mx_island_index \
		mx_island_list \
		mx_matrix_creator \
		mx_pop_front_mini \
		mx_push_back_custom \
		mx_result_matrix \
		mx_sort_result \
		mx_valid_for_1line \
		mx_valid_for_alpha \
		mx_valid_for_digits \
		mx_valid_for_koma \
		mx_valid_for_minus \
		mx_valid_for_slashn \
		mx_validator \
		mx_write_result \
		main \

LIBMX_A = libmx/libmx.a

SRC_PREFFIX = $(addprefix "src/", $(FILES))

HEADER = inc/pathfinder.h

DEL_SRC = $(addsuffix ".c", $(FILES))

SRC = $(addsuffix ".c", $(SRC_PREFFIX))

OBJ = $(addsuffix ".o", $(FILES))

CFLAGS = -std=c11 -Werror -Wall -Wextra -Wpedantic

LIB_A = libmx.a

all: install clean

install:
	@make -C libmx install
	@cp $(HEADER) .
	@cp $(SRC) .
	@cp $(LIBMX_A) .
	@clang $(CFLAGS) -c $(SRC)
	@clang $(CFLAGS) $(OBJ) $(LIB_A) -o $(NAME)
	@mkdir -p obj
	@cp $(OBJ) obj/
	@rm -rf $(OBJ)

uninstall: clean
	@make -C libmx uninstall
	@rm -rf $(NAME)


clean:
	@make -C libmx clean
	@rm -rf obj
	@rm -rf $(DEL_SRC)
	@rm -rf $(OBJ)
	@rm -rf $(LIB_A)
	@rm -rf pathfinder.h

reinstall: uninstall install