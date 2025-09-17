# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 15:34:52 by sylabbe           #+#    #+#              #
#    Updated: 2025/09/17 16:59:42 by sylabbe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Span

CXXFLAGS = -Werror -Wall -Wextra #-std=c++98 #-fno-elide-constructors #-fsanitize=address

SRC_MDT_DIR = .

DEST_MDT_DIR = .

# ls -1 *.c | sed -z 's/\n/ \\\n\t\t\t/g'
SRC =	$(addprefix $(SRC_MDT_DIR)/, main.cpp)


OBJECTS = $(SRC:$(SRC_MDT_DIR)/%.cpp=$(DEST_MDT_DIR)/%.o)

CXX = c++

RM = rm -f

all: $(NAME)


$(NAME): $(OBJECTS)
	@${CXX} ${CXXFLAGS} $(OBJECTS) -o $(NAME) 
	@echo "\033[0;32mMANDATORY COMPILED\033[0m"


$(DEST_MDT_DIR)/%.o: $(SRC_MDT_DIR)/%.cpp #| obj
	@$(CXX) $(CXXFLAGS) -c $< -o $@ -g


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

.PHONY: all clean fclean re