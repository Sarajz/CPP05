NAME = form

CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ_DIR = obj

FILES = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(FILES:.cpp=.o))

all : $(NAME)

$(NAME): $(OBJ_FILES)
	c++ $(CFLAGS) -o $@ $^
	
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	c++ $(CFLAGS) -I./ -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	
fclean: clean 
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re