CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = newZombie.cpp \
		Zombie.cpp \
		main.cpp \
		randomChump.cpp

OBJS_DIR = objs
OBJS = $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

NAME = Zombie

all: $(NAME) 

$(NAME) : $(OBJS) Zombie.hpp
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