# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 16:18:52 by ycyr-roy          #+#    #+#              #
#    Updated: 2023/10/31 12:42:56 by ycyr-roy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = pipex
#==============================================================================#
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Wunreachable-code -Ofast -g
SRC = main.c	utils.c		utils1.c		parse.c		cmd_parse.c \
	cmd_utils.c		error_handler.c
#==============================================================================#
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(addprefix $(BIN_DIR)/, $(SRC:.c=.o))
#==============================================================================#
SRC_DIR     = src
MV_DIR      = moves
BIN_DIR     = bin
INC_DIR     = include
LIBFT_DIR   = lib/libft
LIBFT       = $(LIBFT_DIR)/libft.a
#Shell cmd
MKDIRP = mkdir -p
RM = rm -f
RM_DIR = rm -rf
#==============================================================================#
# headers to include
INCLUDES = -I$(LIBFT_DIR) -I$(INC_DIR) -I$(MV_DIR)
# things to link
LFLAGS =  $(LIBFT)

#==============================================================================#
all: libft $(NAME)
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "$(BLUE)$(BOLD)✅Compiling $(YELLOW)PIPEX $(BLUE)→ $(RESET)$(CYAN)$(notdir $<)        $(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)
	@printf	$(UP)$(CUT)
$(NAME): $(BIN_DIR) $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(LFLAGS)
	@echo "$(GREEN)$(BOLD)✅ Successfully compiled $(YELLOW)PIPEX         $(RESET)"
$(BIN_DIR):
	@$(MKDIRP) $(BIN_DIR)
libft:
	@$(MAKE) -C $(LIBFT_DIR)
bonus: all
	@echo "\n🤯YOO THEY ASKED FOR BONUS OMG🤯\n"
clean:
	@$(RM) $(OBJS)
	@$(RM_DIR) $(BIN_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(GREEN)$(BOLD)✅ Cleaned $(YELLOW)PIPEX$(RESET)"
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)$(BOLD)✅ Fully cleaned $(YELLOW)PIPEX$(RESET)"
re: fclean all
.PHONY: all clean fclean re libft bonus
#=====================================COLORS=====================================#
# Colors
BLACK		=\033[30m
RED			=\033[31m
GREEN       =\033[32m
YELLOW      =\033[33m
BLUE        =\033[34m
PURPLE      =\033[35m
CYAN        =\033[36m
WHITE       =\033[37m
# Text
ERASE       =\033[2K
RESET       =\033[0m
BOLD        =\033[1m
FAINT       =\033[2m
ITALIC      =\033[3m
UNDERLINE   =\033[4m
INVERT      =\033[7m
STRIKE      =\033[9m
# Background
BG_BLACK    =\033[40m
BG_RED      =\033[41m
BG_GREEN    =\033[42m
BG_YELLOW   =\033[43m
BG_BLUE     =\033[44m
BG_PURPLE   =\033[45m
BG_CYAN     =\033[46m
BG_WHITE    =\033[47m
# Others
UP    ="\033[A" # cursor up
CUT   ="\033[K" # cut line
#==============================================================================#
