CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Harl.cpp 


OBJS_DIR = objs
OBJS = $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

NAME = harlFilter

all: $(NAME) 

$(NAME) : $(OBJS) Harl.hpp
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJS_DIR)

re: fclean all

.PHONY:fclean all clean re
