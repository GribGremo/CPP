# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 17:52:07 by sylabbe           #+#    #+#              #
#    Updated: 2024/11/11 11:33:21 by sylabbe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = amateria

CFLAGS = -Werror -Wall -Wextra -std=c++98 #-fsanitize=address

SRC_MDT_DIR = .

DEST_MDT_DIR = .

# ls -1 *.c | sed -z 's/\n/ \\\n\t\t\t/g'
SRC =	$(addprefix $(SRC_MDT_DIR)/, main.cpp \
										AMateria.cpp \
										Character.cpp \
										Cure.cpp \
										Ice.cpp \
										ICharacter.cpp \
										IMateriaSource.cpp \
										MateriaSource.cpp \
										Ground_List.cpp)


OBJECTS = $(SRC:$(SRC_MDT_DIR)/%.cpp=$(DEST_MDT_DIR)/%.o)

CC = c++

RM = rm -f

all: $(NAME)


$(NAME): $(OBJECTS)
	@${CC} ${CFLAGS} $(OBJECTS) -o $(NAME) 
	@echo "\033[0;32mMANDATORY COMPILED\033[0m"


$(DEST_MDT_DIR)/%.o: $(SRC_MDT_DIR)/%.cpp #| obj
	@$(CC) $(CFLAGS) -c $< -o $@ -g


#obj:
#	@mkdir -p $(DEST_MDT_DIR)

clean:
	@$(RM) -r $(OBJECTS) #$(DEST_MDT_DIR) 
	@echo "\033[0;33mCLEAN OBJECTS\033[0m"

fclean: clean
	@$(RM) $(NAME) 
	@echo "\033[0;33mCLEAN EXEC\033[0m"

#re: fclean all
re:
	@${MAKE} fclean all;

MAKEFLAGS         += --no-print-directory

.PHONY: all clean fclean re bonus