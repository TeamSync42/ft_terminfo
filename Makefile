# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/16 11:08:03 by rel-qoqu          #+#    #+#              #
#    Updated: 2025/09/18 12:45:04 by rel-qoqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= ft_terminfo

SRC_DIR				= src
OBJ_DIR				= obj
DEP_DIR				= .deps
INC_DIR				= ./include

INC_FLAGS			= -I$(INC_DIR) -Ilibft/include

CC					= cc
AR					= ar
RANLIB				= ranlib
C_FLAGS				= -std=c17 -Wall -Wextra -Werror -pedantic -MMD -MP $(INC_FLAGS) -fPIC -D_DEFAULT_SOURCE
C_DEBUG_FLAGS		= -Og -g3 -DDEBUG -Wshadow -Wconversion -Wstrict-prototypes \
						-Wmissing-prototypes -Wmissing-declarations -Winline -Wsign-conversion \
						-Wundef -Wcast-align -Wcast-qual -Wwrite-strings -Wuninitialized \
						-Wdouble-promotion -Wvla -Wnull-dereference -Wold-style-definition -Wpadded
C_RELEASE_FLAGS		= -O2 -funroll-loops -fomit-frame-pointer -DNDEBUG

LIBFT_A				= libft/libft.a

INTERNAL_FILES		= internal/hash_termname.c internal/ft_terminfo_init.c internal/ft_terminfo_destroy_entry.c \
						internal/ft_terminfo_destroy.c internal/ft_get_terminfo_entry.c internal/ft_cache_add.c \
						internal/ft_parse_terminfo.c
SRCS_FILES			= $(INTERNAL_FILES) ft_del_curterm.c ft_setupterm.c ft_tgetflag.c \
						ft_tgetnum.c ft_tgetstr.c ft_tputs.c
SRCS				:= $(addprefix $(SRC_DIR)/, $(SRCS_FILES))
OBJS				= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
DEPS				= $(patsubst $(SRC_DIR)/%.c, $(DEP_DIR)/%.d, $(SRCS))

STATIC_LIB			= lib$(NAME).a
SHARED_LIB			= lib$(NAME).so

MODE				:= release
ifeq ($(MODE), release)
	C_FLAGS += $(C_RELEASE_FLAGS)
else ifeq ($(MODE), debug)
	C_FLAGS += $(C_DEBUG_FLAGS)
	NAME = ft_terminfo_debug
	OBJ_DIR = obj_debug
	STATIC_LIB = lib$(NAME).a
	SHARED_LIB = lib$(NAME).so
endif

all: $(STATIC_LIB) $(SHARED_LIB)

$(STATIC_LIB): $(OBJS)
	$(AR) rcs $@ $(OBJS)
	$(RANLIB) $@

$(SHARED_LIB): $(OBJS) $(LIBFT_A)
	$(CC) -shared -o $@ $(OBJS) -Llibft -lft

ifeq ($(MODE), debug)
$(LIBFT_A):
	$(MAKE) -C libft debug -j
else ifeq ($(MODE), release)
$(LIBFT_A):
	$(MAKE) -C libft -j
endif

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D) $(DEP_DIR)
	$(CC) $(C_FLAGS) -c $< -o $@ -MF $(DEP_DIR)/$(*F).d

clean:
	@rm -rf $(DEP_DIR)
	@rm -rf $(OBJ_DIR)*

fclean: clean
	@rm -f $(STATIC_LIB) $(SHARED_LIB)

re: fclean all

debug:
	$(MAKE) MODE=debug

norm:
	@norminette $(INC_DIR)
	@norminette $(SRC_DIR)

.PHONY: all clean fclean re debug norm

-include $(DEPS)

.SECONDARY: $(OBJS)
