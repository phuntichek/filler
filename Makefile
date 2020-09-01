# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/06 16:17:00 by phuntik           #+#    #+#              #
#    Updated: 2020/08/06 16:17:19 by phuntik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------  PROJECT  ----------------------------------------------------- #
NAME	=		filler_rschmele

# ------------  DIRECTORIES  ------------------------------------------------- #
SRC_DIR	=		src
HDR_DIR	=		includes
OBJ_DIR	=		objs

# ------------  LIBFT  ------------------------------------------------------- #
LFT		=		libft.a
LFT_DIR	=		libft
LHS_DIR	=		$(LFT_DIR)

# ------------  SOURCE FILES  ------------------------------------------------ #
SRC_FLS	=		main.c \
			 	init.c \
			 	free.c \
			 	parse_fighter.c \
			 	parse_map.c \
			 	parse_piece.c \
			 	solution.c \
			 	heatmap.c

# ------------  FILEPATHS  --------------------------------------------------- #
SRCS	=		$(addprefix $(SRC_DIR)/, $(SRC_FLS))
OBJS	=		$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRCS))
DEPS	=		$(OBJS:.o=.d)

# ------------  FLAGS  ------------------------------------------------------- #
CC		=		gcc
RM		=		rm -rf
CFLGS	=		-Wall -Werror -Wextra
IFLGS	=		-I $(HDR_DIR) -I $(LHS_DIR)
LFLGS	=		-L $(LFT_DIR) -lft
DFLGS	=		-MMD -MP
DEBUG	=		-g -pg -fsanitize=address

# ------------  RULES  ------------------------------------------------------- #
.PHONY: all clean fclean re

all: $(NAME)

$(LFT_DIR)/$(LFT):
	@echo "\x1b[1m\nBuilding $(LIBFT) library...\x1b[0m"
	$(MAKE) -C $(LFT_DIR)

-include $(DEPS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLGS) $(DFLGS) -c -o $@ $< $(IFLGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(LFT_DIR)/$(LFT) $(OBJS)
	@echo "\x1b[1m\nBuilding $(NAME)...\x1b[0m"
	$(CC) -o $(NAME) $(OBJS) $(LFLGS)

clean:
	@echo "\x1b[1m\nCleaning...\x1b[0m"
	$(MAKE) -C $(LFT_DIR) clean
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all
