# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 11:57:08 by pcatapan          #+#    #+#              #
#    Updated: 2023/11/12 13:16:23 by pcatapan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat

SRC 		= *.cpp

OBJ			= $(SRC:%.cpp=%.o)

CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

#Colors:
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)
	@printf "$(_SUCCESS) $(GREEN)- Executable ready.\n$(RESET)"

clean:
	@$(RM) $(OBJ)
	@printf "$(YELLOW)    - Object files removed.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) *_shrubbery
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re